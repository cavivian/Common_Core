
#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
	char ret;
	if (av[1][0] >= 'a' && av[1][0] <= 'm')
		ret = av[1][0] + 13;
	else
		ret = 97 + ((int)av[1][0] + 13 - 1) % 122;
	// printf("Res: %c\n", ret);
	write(1, &ret, 1);
	write(1, "\n", 1);
}