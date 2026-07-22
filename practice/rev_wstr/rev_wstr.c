#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	if(argc != 2)	
	{
		write(1, "\n", 1);
		return 0;
	}
	int i = 0;
	int start = 0;
	while(argv[1][i])
	{
		i++;
	}
	i--;
	while (i >= 0)
	{
		while(i >= 0 && (argv[1][i] == 32 || (argv[1][i] >= 9 && argv[1][i] <= 13)))
			i--;
		int end = i;
		while(i >= 0 && argv[1][i] != 32 && !(argv[1][i] >= 9 && argv[1][i] <= 13))
			i--;
			
		// printf("non ci sono spazi\n");
		start = i + 1;
		while(start <= end)
		{
			write(1, &argv[1][start], 1);
			start++;
		}
		if(i > 0)
			write(1, " ", 1);
	}
		
	write(1, "\n", 1);
	return 0;
}