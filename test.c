#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int nb = atoi(argv[1]);
	int i = 31;
	while (i >= 0)
		dprintf(1, "%d", (1 & (nb >> i--)));
	dprintf(1, "\n");
	return (0);
}