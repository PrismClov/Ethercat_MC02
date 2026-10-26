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
function New-RecordObject([string]$idx, [string]$name, [string]$dt, [int]$count) {
  $bits = 16 + 8 * $count
  return "<Object><Index>$idx</Index><Name>$name</Name><Type>$dt</Type><BitSize>$bits</BitSize><Info><SubItem><Name>SubIndex 000</Name><Info><DefaultData>$('{0:X2}' -f $count)</DefaultData></Info></SubItem></Info></Object>"
}
function New-MapObject([string]$idx, [string]$name, [string]$dt, [string]$obj, [int]$count) {
  $bits = 16 + 32 * $count
  $sb = New-Object Text.StringBuilder
  [void]$sb.Append("<Object><Index>$idx</Index><Name>$name</Name><Type>$dt</Type><BitSize>$bits</BitSize><Info>")
  [void]$sb.Append("<SubItem><Name>SubIndex 000</Name><Info><DefaultData>$('{0:X2}' -f $count)</DefaultData></Info></SubItem>")
  $hi = ([Convert]::ToInt32($obj.Substring(2,2),16)); $lo = ([Convert]::ToInt32($obj.Substring(4,2),16))
  for ($n = 1; $n -le $count; $n++) {
    $ns = '{0:D3}' -f $n
    $dd = ('08{0:X2}{1:X2}{2:X2}' -f $n, $lo, $hi)
    [void]$sb.Append("<SubItem><Name>SubIndex $ns</Name><Info><DefaultData>$dd</DefaultData><!--Reference to $obj.$n--></Info></SubItem>")
  }
  [void]$sb.Append('</Info></Object>')
  return $sb.ToString()
}
function Replace-One([string]$pattern, [string]$newXml, [string]$what) {
  if (-not [regex]::IsMatch($script:t, $pattern, 'Singleline')) { throw "$what not found" }
  $script:t = [regex]::Replace($script:t, $pattern, [System.Text.RegularExpressions.MatchEvaluator]{ param($m) $newXml }, 'Singleline')
}
Replace-One "<DataType><Name>DT7000</Name>.*?</DataType>" (New-RecordDt 'DT7000' 'r' $outNames) 'DT7000'
Replace-One "<DataType><Name>DT7050</Name>.*?</DataType>" (New-RecordDt 'DT7050' 'r' $uNames) 'DT7050'
Replace-One "<DataType><Name>DT6000</Name>.*?</DataType>" (New-RecordDt 'DT6000' 't' $inNames) 'DT6000'
Replace-One "<DataType><Name>DT60F0</Name>.*?</DataType>" (New-RecordDt 'DT60F0' 't' $rNames) 'DT60F0'
Replace-One "<DataType><Name>DT1600</Name>.*?</DataType>" (New-MapDt 'DT1600' '0x7000' 176) 'DT1600'
Replace-One "<DataType><Name>DT1605</Name>.*?</DataType>" (New-MapDt 'DT1605' '0x7050' 20) 'DT1605'
Replace-One "<DataType><Name>DT1A00</Name>.*?</DataType>" (New-MapDt 'DT1A00' '0x6000' 204) 'DT1A00'
Replace-One "<DataType><Name>DT1A0F</Name>.*?</DataType>" (New-MapDt 'DT1A0F' '0x60F0' 212) 'DT1A0F'
Replace-One "<Object><Index>#x7000</Index>.*?</Object>" (New-RecordObject '#x7000' 'PDOChannel' 'DT7000' 176) 'obj 0x7000'
Replace-One "<Object><Index>#x7050</Index>.*?</Object>" (New-RecordObject '#x7050' 'RMUIPDOChannel' 'DT7050' 20) 'obj 0x7050'
Replace-One "<Object><Index>#x6000</Index>.*?</Object>" (New-RecordObject '#x6000' 'PDIChannel' 'DT6000' 204) 'obj 0x6000'
Replace-One "<Object><Index>#x60F0</Index>.*?</Object>" (New-RecordObject '#x60F0' 'RMDAPDIChannel' 'DT60F0' 212) 'obj 0x60F0'
Replace-One "<Object><Index>#x1600</Index>.*?</Object>" (New-MapObject '#x1600' 'PDOChannel process data mapping' 'DT1600' '0x7000' 176) 'obj 0x1600'
Replace-One "<Object><Index>#x1605</Index>.*?</Object>" (New-MapObject '#x1605' 'RMUIPDOChannel process data mapping' 'DT1605' '0x7050' 20) 'obj 0x1605'
Replace-One "<Object><Index>#x1A00</Index>.*?</Object>" (New-MapObject '#x1A00' 'PDIChannel process data mapping' 'DT1A00' '0x6000' 204) 'obj 0x1A00'
Replace-One "<Object><Index>#x1A0F</Index>.*?</Object>" (New-MapObject '#x1A0F' 'RMDAPDIChannel process data mapping' 'DT1A0F' '0x60F0' 212) 'obj 0x1A0F'
$bytes = [Text.Encoding]::UTF8.GetBytes($script:t)
$fs = [IO.File]::Create($esp)
$gz2 = New-Object IO.Compression.GZipStream($fs, [IO.Compression.CompressionMode]::Compress)
$gz2.Write($bytes, 0, $bytes.Length); $gz2.Dispose(); $fs.Dispose()
Write-Output "updated: $esp"
