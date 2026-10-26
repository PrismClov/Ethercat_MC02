param([string]$Dir = 'D:\ethercat\Horizon_EtherCAT-master\Slave\MC02_LAN9252\EcatDemoMC02\User\SSC')
$ErrorActionPreference = 'Stop'
$esp = Join-Path $Dir 'SSC_Device.esp'
Copy-Item -LiteralPath $esp -Destination "$esp.bak" -Force
$in = [IO.File]::OpenRead($esp)
$gz = New-Object IO.Compression.GzipStream($in, [IO.Compression.CompressionMode]::Decompress)
$ms = New-Object IO.MemoryStream
$gz.CopyTo($ms); $gz.Dispose(); $in.Dispose()
$script:t = [Text.Encoding]::UTF8.GetString($ms.ToArray()); $ms.Dispose()
$axes = New-Object System.Collections.Generic.List[string]
foreach ($b in 1..3) {
  $letters = if ($b -eq 3) { @('A','B','C') } else { @('A','B','C','D','E','F','G') }
  foreach ($l in $letters) { $axes.Add("C${b}$l") }
}
$outNames = New-Object System.Collections.Generic.List[string]
$outNames.AddRange([string[]]@('Ctrl','Seq1','Seq2','Seq3'))
foreach ($p in $axes) { $outNames.AddRange([string[]]@("${p}P1","${p}P2","${p}V1","${p}V2","${p}T1","${p}T2","${p}KP1","${p}KP2","${p}KD1","${p}KD2")) }
$outNames.AddRange([string[]]@('Pad1','Pad2'))
$inNames = New-Object System.Collections.Generic.List[string]
$inNames.AddRange([string[]]@('AX1','AX2','AY1','AY2','AZ1','AZ2','GX1','GX2','GY1','GY2','GZ1','GZ2'))
foreach ($p in $axes) { $inNames.AddRange([string[]]@("${p}ID1","${p}ID2","${p}P1","${p}P2","${p}P3","${p}P4","${p}V1","${p}V2","${p}ST1","${p}ST2")) }
$inNames.AddRange([string[]](1..21 | ForEach-Object { "VT$_" }))
$inNames.Add('end1')
$uNames = New-Object System.Collections.Generic.List[string]
$uNames.AddRange([string[]](1..20 | ForEach-Object { "U$_" }))
$rNames = New-Object System.Collections.Generic.List[string]
$rNames.AddRange([string[]](1..212 | ForEach-Object { "R$_" }))
if ($outNames.Count -ne 176) { throw "0x7000=$($outNames.Count)" }
if ($inNames.Count -ne 204) { throw "0x6000=$($inNames.Count)" }
function New-RecordDt([string]$dtName, [string]$map, $names) {
  $bits = 16 + 8 * $names.Count
  $sb = New-Object Text.StringBuilder
  [void]$sb.Append("<DataType><Name>$dtName</Name><BitSize>$bits</BitSize>")
  [void]$sb.Append("<SubItem><SubIdx>0</SubIdx><Name>SubIndex 000</Name><Type>USINT</Type><BitSize>8</BitSize><BitOffs>0</BitOffs><Flags><Access>ro</Access><Category>o</Category></Flags></SubItem>")
  for ($i = 0; $i -lt $names.Count; $i++) {
    $n = $i + 1; $offs = 8 + 8 * $n
    [void]$sb.Append("<SubItem><SubIdx>$n</SubIdx><Name>$($names[$i])</Name><Type>USINT</Type><BitSize>8</BitSize><BitOffs>$offs</BitOffs><Flags><Access>rw</Access><PdoMapping>$map</PdoMapping></Flags></SubItem>")
  }
  [void]$sb.Append('</DataType>')
  return $sb.ToString()
}
function New-MapDt([string]$dtName, [string]$obj, [int]$count) {
  $bits = 16 + 32 * $count
  $sb = New-Object Text.StringBuilder
  [void]$sb.Append("<DataType><Name>$dtName</Name><BitSize>$bits</BitSize>")
  [void]$sb.Append("<SubItem><SubIdx>0</SubIdx><Name>SubIndex 000</Name><Type>USINT</Type><BitSize>8</BitSize><BitOffs>0</BitOffs><Flags><Access>ro</Access><Category>o</Category></Flags></SubItem>")
  for ($n = 1; $n -le $count; $n++) {
    $offs = 16 + 32 * ($n - 1); $ns = '{0:D3}' -f $n
    [void]$sb.Append("<SubItem><SubIdx>$n</SubIdx><Name>SubIndex $ns</Name><Type>UDINT</Type><BitSize>32</BitSize><BitOffs>$offs</BitOffs><Flags><Access>ro</Access></Flags><!--Reference to $obj.$n--></SubItem>")
  }
  [void]$sb.Append('</DataType>')
  return $sb.ToString()
}
function Replace-Dt([string]$dtName, [string]$newXml) {
  $pat = "<DataType><Name>$dtName</Name>.*?</DataType>"
  if (-not [regex]::IsMatch($script:t, $pat, 'Singleline')) { throw "DataType $dtName not found" }
  $script:t = [regex]::Replace($script:t, $pat, [System.Text.RegularExpressions.MatchEvaluator]{ param($m) $newXml }, 'Singleline')
}
function Set-ObjectMeta([string]$idx, [int]$bits, [int]$sub0) {
  $pat = "<Object><Index>$([regex]::Escape($idx))</Index>.*?</Object>"
  $m = [regex]::Match($script:t, $pat, 'Singleline')
  if (-not $m.Success) { throw "Object $idx not found" }
  $body = $m.Value
  $body = [regex]::Replace($body, '<BitSize>\d+</BitSize>', "<BitSize>$bits</BitSize>", 1)
  $body = [regex]::Replace($body, '<DefaultData>[0-9A-Fa-f]+</DefaultData>', ('<DefaultData>{0:X2}</DefaultData>' -f $sub0), 1)
  $script:t = $script:t.Replace($m.Value, $body)
}
Replace-Dt 'DT7000' (New-RecordDt 'DT7000' 'r' $outNames)
Replace-Dt 'DT7050' (New-RecordDt 'DT7050' 'r' $uNames)
Replace-Dt 'DT6000' (New-RecordDt 'DT6000' 't' $inNames)
Replace-Dt 'DT60F0' (New-RecordDt 'DT60F0' 't' $rNames)
Replace-Dt 'DT1600' (New-MapDt 'DT1600' '0x7000' 176)
Replace-Dt 'DT1605' (New-MapDt 'DT1605' '0x7050' 20)
Replace-Dt 'DT1A00' (New-MapDt 'DT1A00' '0x6000' 204)
Replace-Dt 'DT1A0F' (New-MapDt 'DT1A0F' '0x60F0' 212)
Set-ObjectMeta '#x7000' (16 + 8 * 176) 176
Set-ObjectMeta '#x7050' (16 + 8 * 20) 20
Set-ObjectMeta '#x6000' (16 + 8 * 204) 204
Set-ObjectMeta '#x60F0' (16 + 8 * 212) 212
Set-ObjectMeta '#x1600' (16 + 32 * 176) 176
Set-ObjectMeta '#x1605' (16 + 32 * 20) 20
Set-ObjectMeta '#x1A00' (16 + 32 * 204) 204
Set-ObjectMeta '#x1A0F' (16 + 32 * 212) 212
$bytes = [Text.Encoding]::UTF8.GetBytes($script:t)
$fs = [IO.File]::Create($esp)
$gz2 = New-Object IO.Compression.GZipStream($fs, [IO.Compression.CompressionMode]::Compress)
$gz2.Write($bytes, 0, $bytes.Length); $gz2.Dispose(); $fs.Dispose()
Write-Output "updated: $esp"
