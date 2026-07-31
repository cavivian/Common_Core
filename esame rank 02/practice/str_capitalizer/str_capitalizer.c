#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	int args = 1;
	while (args < argc)
	{
		int i = 0;
		while(argv[args][i])
		{
			if (argv[args][i] >= 'A' && argv[args][i] <= 'Z')
				argv[args][i] += 32;
			if (i == 0 || (i > 0 && argv[args][i - 1] == 32 && (argv[args][i] >= 'a' && argv[args][i] <= 'z')))
				argv[args][i] -= 32;
			write(1, &argv[args][i], 1);
			i++;
		}
		args++;
	}
	write(1, "\n", 1);
	return 0;
}