target extended-remote localhost:2331
watch *(unsigned short *)0x200017E0
commands
silent
printf "WATCH val=%u\n", *(unsigned short *)0x200017E0
bt 8
continue
end
continue
