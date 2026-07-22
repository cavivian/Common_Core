#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;
	while(str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while(str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
		{
			write(1, "-", 1);
			sign *= -1;
		}
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}
void ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	char c = (n % 10) + 48;
	write(1, &c, 1);
}


int is_prime(int n)
{
	if (n == 1)
	{
		//ft_putnbr(n);
		return 0;
	}
	int divisore = 2;
	int primo = 1;
	int tmp = n;
	int risultato = 0;
	while(divisore < n)
	{
		risultato = tmp % divisore;
		if (risultato == 0)
		{
			primo = 0;
			break;
		}
		divisore++;
	}
	if(primo == 1)
		return (risultato);
	else
		return -1;
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		write(1, "0\n", 2);
		return 0;
	}
	int conv = ft_atoi(argv[1]);
	int risultato = 0;
	int i = 0;
	while(i <= conv)
	{
		risultato += is_prime(conv);
		i++;
	}
	ft_putnbr(risultato);
	write(1, "\n", 1);
	return 0;
}