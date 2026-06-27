#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//	ES-1- da rivedere
// int main(int argc, char *argv[])
// {
// 	if (argc != 2)
// 	{
// 		write(1, "\n", 1);
// 		return 0;
// 	}
// 	int i = 0;
// 	while ((argv[1][i] == 32) || (argv[1][i] >= 9 && argv[1][i] <= 13))
// 		i++;
// 	while (argv[1][i] && !(argv[1][i] >= 9 && argv[1][i] <= 13) && !(argv[1][i] == 32))
// 	{
// 		write (1, &argv[1][i], 1);
// 		i++;
// 	}
// 	write(1, "\n", 1);
// 	return 0;
// }


//	ES-2- -> torna!
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


//	ES-3- -> torna!
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


//	ES-4- -> torna!
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


//	ES-5- -> torna!
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


//	ES-6- -> torna!
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


//	ES-7- (last_word) -> 
// int main(int argc, char *argv[])
// {
// 	if (argc != 2)
// 	{
// 		write (1, "\n", 1);
// 		return 0;
// 	}
// 	int i = 0;
// 	int j = 0;
// 	while (argv[1][i] != '\0')
// 	{
// 		i++;
// 	}
// 	i--;
// 	while (argv[1][i] == 32 || (argv[1][i] >= 9 && argv[1][i] <= 13))
// 		i--;
// 	while ((i > 0 && argv[1][i] != 32) && !(argv[1][i] >= 9 && argv[1][i] <= 13))
// 	{
// 		i--;
// 	}
// 	j = i + 1;
// 	while(argv[1][j] != '\0' && !(argv[1][j] >= 9 && argv[1][j] <= 13) && argv[1][j] != 32)
// 	{
// 		write(1, &argv[1][j], 1);
// 		j++;
// 	}
// 	write (1, "\n", 1);
// 	return 0;
// }


//	ES-8- (repeat alpha) -> torna!
// int main(int argc, char *argv[])
// {
// 	if (argc != 2)
// 	{
// 		write(1, "\n", 1);
// 		return 0;
// 	}
// 	int i = 0;
// 	int lettere_da_stampare;
// 	while(argv[1][i] != '\0')
// 	{
// 		lettere_da_stampare = 1;
// 		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
// 		{
// 			lettere_da_stampare = argv[1][i] - 'a' + 1;
// 		}
// 		else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
// 			lettere_da_stampare = argv[1][i] - 'A' + 1;
// 		while(lettere_da_stampare > 0 && argv[1][i] != '\0')
// 		{
// 			write(1, &argv[1][i], 1);
// 			lettere_da_stampare--;
// 		}
// 		i++;
// 	}
// 	write(1, "\n", 1);
// 	return 0;
// }


//	ES -8- (rev print) -> torna!
// int main(int argc, char *argv[])
// {
// 	if (argc != 2)
// 	{
// 		write (1, "\n", 1);
// 		return (0);
// 	}
// 	int i = 0;
// 	while (argv[1][i] != '\0')
// 	{
// 		i++;
// 	}
// 	i--;
// 	while (argv[1][i] > 0)
// 	{
// 		write (1, &argv[1][i], 1);
// 		i--;
// 	}
// 	write(1, "\n", 1);
// 	return 0;
// }


//	ES -9- (rot_13) -> fatto
// char printletters(char c)
// {
// 	if ((c >= 'a' && c <= 'm') || (c >= 'n' && c <= 'z'))
// 		return (c );
// 	else if ((c >= 'A' && c <= 'M') || (c >= 'N' && c <= 'Z'))
// 		return (c);
// 	return 0;
// }

// int main(int argc, char *argv[])
// {
// 	if (argc != 2)
// 	{
// 		write (1, "\n", 1);
// 		return 0;
// 	}
// 	int i = 0;
// 	while(argv[1][i] != '\0')
// 	{
// 		if ((argv[1][i] >= 'a' && argv[1][i] <= 'z') || (argv[1][i] >= 'A' && argv[1][i] <= 'Z'))
// 		{
// 			argv[1][i] = printletters(*argv[1]);
// 		}
// 		write(1, &argv[1][i], 1);
// 		i++;
// 	}
// 	write(1, "\n", 1);
// 	return 0;
// }


// ES -10- (rotone) -> torna!
// int main(int argc, char *argv[])
// {
// 	if (argc != 2)
// 	{
// 		write(1, "\n", 1);
// 		return 0;
// 	}
// 	int i = 0;
// 	while (argv[1][i] != '\0')
// 	{
// 		if(argv[1][i] >= 'a' && argv[1][i] <= 'z')
// 		{
// 			if (argv[1][i] == 'z')
// 				argv[1][i] = 'a';
// 			argv[1][i] += 1;
// 		}
// 		else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
// 		{
// 			if (argv[1][i] == 'Z')
// 				argv[1][i] = 'A';
// 			argv[1][i] += 1;
// 		}
// 		write(1, &argv[1][i], 1);
// 		i++;
// 	}
// 	write(1, "\n", 1);
// 	return 0;
// }


//	ES -11- (search and replace) -> torna!
// int main(int argc, char *argv[])
// {
// 	if (argc != 4 || argv[2][0] == '\0' || argv[2][1] != '\0' || argv[3][0] == '\0' || argv[3][1] != '\0')
// 	{
// 		write(1, "\n", 1);
// 		return 0;
// 	}
// 	int i = 0;
// 	while (argv[1][i] != '\0')
// 	{
// 		if (argv[1][i] == argv[2][0])
// 			argv[1][i] = argv[3][0];
// 		write (1, &argv[1][i], 1);
// 		i++;
// 	}
// 	write(1, "\n", 1);
// 	return 0;
// }


//	ES -12- (ulstr) -> torna!
// int main(int argc, char *argv[])
// {
// 	if (argc != 2)
// 	{
// 		write(1, "\n", 1);
// 		return 0;
// 	}
// 	int i = 0;
// 	while (argv[1][i] != '\0')
// 	{
// 		if(argv[1][i] >= 'a' && argv[1][i] <= 'z')
//  			argv[1][i] -= 32;
// 		else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
//  			argv[1][i] += 32;
// 		write(1, &argv[1][i], 1);
// 		i++;
// 	}
// 	write (1, "\n", 1);
// 	return 0;
// }


//	- - LIVELLO 2 - -
//	ES -1- (alpha mirror) -> torna!
// int main(int argc, char *argv[])
// {
// 	if (argc != 2)
// 	{
// 		write(1, "\n", 1);
// 		return 0;
// 	}
// 	int i = 0;
// 	while (argv[1][i] != '\0')
// 	{
// 		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
// 			argv[1][i] = 'a' + 'z' - argv[1][i];
// 		else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
// 			argv[1][i] = 'A' + 'Z' - argv[1][i];
// 		write(1, &argv[1][i], 1);
// 		i++;
// 	}
// 	write(1, "\n", 1);
// 	return 0;
// }


//	ES -2- (camel to snake) -> torna ma non ho usato malloc e realloc
// int main(int argc, char *argv[])
// {
// 	if (argc != 2)
// 	{
// 		write(1, "\n", 1);
// 		return 0;
// 	}
// 	int i = 0;
// 	while (argv[1][i] != '\0')
// 	{
// 		if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
// 			write(1, "_", 1);
// 		if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
// 			argv[1][i] += 32;
// 		write(1, &argv[1][i], 1);
// 		i++;
// 	}
// 	write(1, "\n", 1);
// 	return 0;
// }


//	ES -3- (do op) -> torna!
// int main(int argc, char *argv[])
// {
// 	if (argc != 4)
// 	{
// 		write(1, "\n", 1);
// 		return 0;
// 	}
// 	int arg = 0;
// 	int dividendo = atoi(argv[1]);
// 	int divisore = atoi(argv[3]);
// 	int risultato = 0;
// 	if (arg < argc)
// 	{
// 		if (argv[2][0] == '+')
// 			risultato = (dividendo + divisore);
// 		else if (argv[2][0] == '-')
// 			risultato = (dividendo - divisore);
// 		else if (argv[2][0] == '/')
// 			risultato = (dividendo / divisore);
// 		else if (argv[2][0] == '%')
// 			risultato = (dividendo % divisore);
// 		printf("%d\n", risultato);
// 	}
// 	//write(1, "\n", 1);
// 	return 0;
// }


//	ES -4- -> da fare quando sono piu' concentrata
// int ft_atoi(const char *str)
// {
// 	if (!str)
// 		return 0;
// 	int sign = 1;
// 	int result = 0;
// 	int i = 0;
// 	if (str[i] < 0)

// }


//	ES -5- -> torna!
// int ft_strcmp(char *s1, char *s2)
// {
// 	int i = 0;
// 	int j = 0;
// 	while(s1[i])
// 	{
// 		i++;
// 	}
// 	while (s2[j])
// 		j++;
// 	return (i - j);
// }

// int main()
// {
// 	char *s1 = "ciao";
// 	char *s2 = "ciao mamma";
// 	printf("%d", ft_strcmp(s2, s1));
// 	return 0;
// }


//	ES -6- 
size_t ft_strcspn(const char *s, const char *reject)
{
	
}