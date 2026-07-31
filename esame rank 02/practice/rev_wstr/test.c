#include <unistd.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	int i = 0;
	int start;
	int end;
	while(argv[1][i])
		i++;
	i--;
	while(i >= 0)
	{
		while((i >= 0 && argv[1][i] == 32 )|| (argv[1][i] >= 9 && argv[1][i] <= 13))
			i--;
		end = i;
		while(i >= 0 && argv[1][i] != 32 && !(argv[1][i] >= 9 && argv[1][i] <= 13))
			i--;
		start = i + 1;
		while(start <= end)
		{
			write(1, &argv[1][start], 1);
			start++;
		}
		if ( i > 0)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
	return 0;
}