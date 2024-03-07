## level2

Useful infos:
```
0x68 = 104
0x4c = 76

adresse de "/bin/sh/": 0xb7f8cc58
adresse de libc: 0xb7e2c000
adresse de system: 0xb7e6b060
adresse de ret: 0x0804853e

segfault a  

esp -> gets ret pointer
0
0
gets string start
0
0
0
0
0
0
old ebp
p ret pointer
```

We can redirect the execution of the `ret` of the `p` function to `system` (in the libc).
But there is a check that prevents us from using the address of `system` directly, so
we ret to a `ret` that will ret to `system` with argument "/bin/sh" (found in the libc as well).