#include <stdio.h>
#include <unistd.h>

//	ES-1- da rivedere
// int main(int argc, char *argv[])
// {
// 	if (argc != 2)
// 	{
// 		write(1, "\n", 1);
// 		return 0;
// 	}
// 	int i = 0;
// 	if ((argv[1][0] == 32) || (argv[1][0] >= 9 && argv[1][0] <= 13))
// 		i++;
// 	while (argv[1][i] != '\0')
// 	{
// 		if (!(argv[1][i] >= 9 && argv[1][i] <= 13) || !(argv[1][i] == 32))
// 		{
// 			write (1, &argv[1][i], 1);
// 		}
// 		i++;
// 	}
// 	write(1, "\n", 1);
// 	return 0;
// }


//	ES-2- 
// char print_numb(int c)
// {
// 	if (c >= 10)
// 		print_numb(c / 10);
// 	c = c % 10 + 48;
// 	write(1, &c, 1);
// }

// void fizzbuzz()
// {
// 	int n = 1;
// 	while (n <= 10 * 10)
// 	{
// 		if (n % 3 == 0 && n % 5 != 0)
// 			write(1, "fizz", 4);
// 		else if (n % 5 == 0 && n % 3 != 0)
// 			write(1, "buzz", 4);
// 		else if (n % 5 == 0 && n % 3 == 0)
// 			write(1, "fizzbuzz", 1);
// 		else
// 			print_numb(n);
// 		n++;
// 		write(1, "\n", 1);
// 	}
// }

// int main()
// {
// 	fizzbuzz();
// }


//	ES-3-
// void ft_putstr(char *str)
// {
// 	int i = 0;
// 	while (str[i] != '\0')
// 	{
// 		write(1, &str[i], 1);
// 		i++;
// 	}
// }

// int main()
// {
// 	char *str = "ciao mamma";
// 	ft_putstr(str);
// 	return 0;
// }


//	ES-4-
// char *ft_strcpy(char *s1, char *s2)
// {
// 	int i = 0;
// 	while(s2[i] != '\0')
// 	{
// 		s1[i] = s2[i];
// 		i++;
// 	}
// 	return(s2);
// }

// int main()
// {
// 	char *sorgente = "ciao mamma";
// 	char dest[100];
// 	printf("%s\n", ft_strcpy(sorgente, dest));
// 	return(0);
// }


//	ES-5-
// int ft_strlen(char *str)
// {
// 	int i = 0;
// 	while (str[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// int main()
// {
// 	char *str = "ciao mamma";
// 	printf("%d", ft_strlen(str));
// 	return (0);
// }


//	ES-6-
// void	ft_swap(int *a, int *b)
// {
// 	int tmp;
// 	tmp = *a;
// 	*a = *b;
// 	*b = tmp;
// }

// int main()
// {
// 	int a = 5;
// 	int b = 6;
// 	ft_swap(&a, &b);
// 	printf("%d\n", a);
// 	printf("%d\n", b);
// 	return 0;
// }


//	ES-7- (last_word)
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write (1, "\n", 1);
		return 0;
	}
	int i = 0;
	while (argv[1][i] != '\0')
	{
		i++;
	}
	i--;
	if (argv[1][i] == 32 || (argv[1][i] >= 9 && argv[1][i] <= 13))
		i--;
	while (argv >= 1)
}