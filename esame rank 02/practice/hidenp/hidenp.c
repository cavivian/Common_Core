#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return 0;
	}
	int i = 0;
	int j = 0;
	while(argv[2][i] && argv[1][j])
	{
		if (argv[1][j] == argv[2][i])
		{
			if (argv[1][j] == '\0')
				break ;
			j++;
		}
		i++;
	}
	if (argv[1][j] == '\0')
		write(1, "1\n", 2);
	else
		write(1, "0\n", 2);
	return 0;
}