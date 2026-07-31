#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int i = 7;
	while(i >= 0)
	{
		if (octet & (1 << i))
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i--;
	}
}

int main(void)
{
	unsigned char octet = 2; // Example value
	print_bits(octet);
	write(1, "\n", 1); // Newline for better readability
	return 0;
}