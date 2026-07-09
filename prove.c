#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


//	- LIVELLO 1 -
//	ES -1- (first word) -> torna!
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


//	ES -2- -> torna!
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


//	ES -3- -> torna!
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


//	ES -4- -> torna!
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


//	ES -5- -> torna!
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


//	ES-7- (last_word) -> torna!
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


//	ES -9- (rot_13) -> torna!
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
// 		if ((argv[1][i] >= 'a' && argv[1][i] <= 'm') || (argv[1][i] >= 'A' && argv[1][i] <= 'M'))
//             argv[1][i] += 13;
//         else if (argv[1][i] >= 'n' && argv[1][i] <= 'z')
// 			argv[1][i] = 'a' + (argv[1][i] + 12)  % 'z';
//         else if (argv[1][i] >= 'N' && argv[1][i] <= 'Z')
//             argv[1][i] = 'A' + (argv[1][i] + 12) % 'Z';
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


//	ES -4- -> torna!
// int ft_atoi(const char *str)
// {
// 	if (!str)
// 		return 0;
// 	int sign = 1;
// 	int result = 0;
// 	int i = 0;
// 	while(str[i] == 32 || str[i] >= 9 && str[i] <= 13)
// 		i++;
// 	while (str[i] == '+' ||  str[i] == '-')
// 	{
// 		if (str[i] == '-')
// 		{
// 			write(1, "-", 1);
// 			sign *= -1;
// 		}
// 		i++;
// 	}
// 	while(str[i] >= '0' && str[i] <= '9')
// 	{
// 		result = result * 10 + (str[i] - 48);
// 		i++;
// 	}
// 	return(result * sign);
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


//	ES -6- -> torna!
// size_t ft_strcspn(const char *s, const char *reject)
// {
// 	size_t i = 0;
//     size_t j = 0;
//     while(s[i] != reject[j])
//     {
//         i++;
//     }
//     return (i);
// }

// int main()
// {
//     char *s = "ciao mamma";
//     char *reject = "o";
//     printf("%ld\n", ft_strcspn(s, reject));
//     return 0;
// }


//  ES -7- -> torna!
// char    *ft_strdup(char *src)
// {
//     int i = 0;
//     int j = 0;
//     char *dest = malloc(sizeof(src) + 1);
//     if (!dest)
//         return NULL;
//     while (src[i] != '\0')
//     {
//         dest[j] = src[i];
//         i++;
//         j++;
//     }
//     return (dest);
// }

// int main()
// {
//     char *str = "ciao mamma ";
//     printf("%s\n", ft_strdup(str));
//     printf("%s\n", strdup(str));

//     return 0;
// }


//  ES -8- ->  torna!
// char	*ft_strpbrk(const char *s1, const char *s2)
// {
//     int i = 0;
//     int j;
// 	while (s1[i])
// 	{
// 		j = 0;
// 		while(s2[j])
// 		{
// 			if (s1[i] == s2[j])
// 				return ((char *)&s1[i]);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// int main()
// {
//     // char *s1 = "ciao mamma";
//     // char *s2 = "ma";
// 	char a[20] = "ciao mondo";
// 	char *tmp = &a[3];
// 	printf("a: %s, tmp: %s\n", a, tmp);
// 	a[5] = 't';
// 	printf("a: %s, tmp: %s\n", a, tmp);
//     printf("%s\n", ft_strpbrk(a, tmp));
//     printf("%s\n", strpbrk(a, tmp));
//     return 0;
// }


//	ES -9- -> torna!
// char *ft_strrev(char *str)
// {
// 	int start = 0;
// 	int end = 0;
// 	char tmp;
// 	while (str[end] != '\0')
// 	{
// 		end++;
// 	}
// 	end--;
// 	while(start < end)
// 	{
// 		tmp = str[start];
// 		str[start] = str[end];
// 		str[end] = tmp;
// 		start++;
// 		end--;
// 	}
// 	return (str);
// }

// int main()
// {
// 	char str[] = "ciao mamma";
// 	printf("%s\n", ft_strrev(str));
// 	return 0;
// }


#include <string.h>
//	ES -10- -> torna!
// size_t ft_strspn(const char *s, const char *accept)
// {
// 	if (!s || !accept)
// 		return 0;
// 	int i = 0;
// 	int j = 0;
// 	size_t contatore = 0;
// 	while(s[i] != '\0')
// 	{
// 		j = 0;
// 		while(accept[j])
// 		{
// 			if (s[i] == accept[j])
// 			{
// 				contatore++;
// 				break ;
// 			}
// 			j++;
// 		}
// 		if (!accept[j])
// 			return (contatore);
// 		i++;
// 	}
// 	return (0);
// }

// int main()
// {
// 	char *s = "ciao mamma";
// 	char *accepted = "ica";
// 	printf("%zu\n", ft_strspn(s, accepted));
// 	printf("%zu\n", strspn(s, accepted));
// 	return 0;
// }


//	ES -11- -> torna!
// int is_power_of_2(unsigned int n)
// {
// 	while (n != 0)
// 	{
// 		if (n % 2 == 0)
// 			return 1;
// 		else
// 			return 0;
// 	}
// 	write(1, "\n", 1);
// 	return 0;
// }

// int main()
// {
// 	unsigned int n = 97;
// 	printf("%d", is_power_of_2(n));
// 	return 0;
// }


//	ES -12- -> torna!
// int max(int *tab, unsigned int len)
// {
// 	if (!tab)
// 		return 0;
// 	unsigned int i = 0;
// 	int max_val = tab[i];
// 	while (i < len)
// 	{
// 		printf("Max: %d > tab[i]: %d\n", max_val, tab[i]);
// 		if (tab[i] > max_val)
// 		{
// 			max_val = tab[i];
// 			printf("Si, max = %d\n", tab[i]);
// 		}
// 		else
// 			printf("No, max = %d\n", max_val);
// 		i++;
// 	}
// 	return max_val;
// }


// int main()
// {
// 	int tab[] = {22, 33, 11};
// 	unsigned int len = 3;
// 	printf("%d\n", max(tab, len));
// 	return 0;
// }


//	ES -13-
// void print_bits(unsigned char octet)
// {
// 	int i = 7;
// 	unsigned char bit;
// 	while(i >= 0)
// 	{
//		if (octet & (1 << i))
//			bit = '1';
//		else
//			bit = '0';
// 		write(1, &bit, 1);
// 		i++;
// 	}
// }

// int main()
// {
// 	unsigned char octet = 42;
// 	print_bits(octet);
// 	return 0;
// }


//	ES -14- -> non torna, c'e' da capire per bene i bit
// unsigned char reverse_bits(unsigned char octet)
// {
// 	int i = 0;
// 	unsigned char bit;
// 	while (i <= 7)
// 	{
//		if (octet & (1 << 1))
// 			bit = bit | (1 << (7 - i));
// 		i++;
// 	}
// 	return (bit);
// }


// int main()
// {
// 	unsigned char octet = 2;
// 	printf("%d\n", reverse_bits(octet));
// 	return 0;
// }


//	ES -15- -> da fare quando ho capito i bit
// unsigned char swap_bits(unsigned char octet)
// {
//		return((octet << 4) | (octet >> 4));
// }


//	ES -16- (union) -> scambia due lettere, da capire perchè
// int main(int argc, char *argv[])
// {
// 	if (argc != 3)
// 	{
// 		write(1, "\n", 1);
// 		return 0;
// 	}
// 	int i = 0;
// 	//int j = 0;
// 	char tmp[256] = {0};
// 	while(argv[1][i] != '\0')
// 	{
// 		if(tmp[(int)argv[2][i]] == 0 && tmp[(int)argv[1][i]] == 0)
// 		{
// 			write(1, &argv[1][i], 1);
// 			tmp[(int)argv[1][i]] = 1;
// 			//j++;
// 		}
// 		i++;
// 	}
// 	while(argv[2][i] != '\0')
// 	{
// 		if(tmp[(int)argv[2][i]] == 0 && tmp[(int)argv[1][i]] == 1)
// 		{
// 			write(1, &argv[2][i], 1);
// 			tmp[(int)argv[2][i]] = 1;
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	write(1, "\n", 1);
// 	return 0;
// }

// int main(int argc, char *argv[])
// {
// 	if(argc != 3)
// 	{
// 		write(1, "\n", 1);
// 		return 0;
// 	}
// 	int i = 0;
// 	int j;
// 	while (argv[2][i])
// 	{
// 		j = 0;
// 		while(argv[1][j] != '\0')
// 		{
// 			if (argv[1][j] == argv[2][i])
// 			 	i++;
// 			if (argv[1][j] == '\0')
// 				break ;
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (argv[1][j] == '\0')
// 		write(1, &argv[1][j], 1);
// 	else
// 		write (1, "\n", 1);
// 	return 0;
// }


//	ES -17- (wdmatch) -> stessa cosa di union solo che stampa solo argv[1]


//	- - - LIVELLO 3 - - -
//	ES -1- (add_prime_sum) -> funzione is_prime non va bene, fatto male
// int ft_atoi(char *str)
// {
// 	int i = 0;
// 	int sign = 1;
// 	int result = 0;
// 	while(str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
// 		i++;
// 	while(str[i] == '+' || str[i] == '-')
// 	{
// 		if (str[i] == '-')
// 			sign *= -1;
// 		i++;
// 	}
// 	while(str[i] >= '0' && str[i] <= '9')
// 	{
// 		result = result * 10 + (str[i] - 48);
// 		i++;
// 	}
// 	return (result * sign);
// }

// void ft_putnbr(int n)
// {
// 	char c;
// 	long nbr = (long)n;
// 	if (nbr < 0)
// 	{
// 		write(1, "-", 1);
// 		nbr = -nbr;
// 	}
// 	if (nbr > 9)
// 	{
// 		ft_putnbr(nbr / 10);
// 	}
// 	c = nbr % 10 + 48;
// 	write(1, &c, 1);
// }

// int is_prime(int n)
// {
// 	int i = 2;
// 	if (n <= 1)
// 		return 0;
// 	while (i < n)
// 	{
// 		if (n % i == 0)
// 			return 0;
// 		i++;
// 	}
// 	return 1;
// }

// int main(int argc, char *argv[])
// {
// 	if(argc != 2)
// 	{
// 		write(1, "\n", 1);
// 		return 0;
// 	}
// 	//int i = 0;
// 	int conv = ft_atoi(argv[1]);
// 	int result;
// 	while(0 >= conv)
// 	{
// 		write(1, "0\n", 2);
// 		return 0;
// 	}
// 	while(conv > 1)
// 	{
// 		if(is_prime(conv) == 1)
// 			result += conv;
// 		conv--;
// 	}
// 	ft_putnbr(result);
// 	write(1, "\n", 1);
// 	return 0;
// }


//	ES -2- (epur str) -> torna!
// int main(int argc, char *argv[])
// {
// 	if (argc != 2)
// 	{
// 		write (1, "\n", 1);
// 		return 0;
// 	}
// 	int i = 0;
// 	int flag = 0;
// 	while (argv[1][i] == 32 || (argv[1][i] >= 9 && argv[1][i] <= 13))
// 		i++;
// 	while (argv[1][i] != '\0')
// 	{
// 		while (argv[1][i] != '\0' && argv[1][i] != 32 && !(argv[1][i] >= 9 && argv[1][i] <= 13))
// 		{
// 				if (flag == 1)
// 				{
// 					write(1, " ", 1);
// 					flag = 0;
// 				}
// 				write(1, &argv[1][i], 1);
// 				i++;
// 		}
// 		while (argv[1][i] == 32 || (argv[1][i] >= 9 && argv[1][i] <= 13))
// 		{
// 			flag = 1;
// 			i++;
// 		}
// 	}
// 	write(1, "\n", 1);
// 	return 0;
// }


//	ES -3- (expand str) -> torna!
// int main(int argc, char *argv[])
// {
// 	if (argc != 2)
// 	{
// 		write(1, "\n", 1);
// 		return 0;
// 	}
// 	int i = 0;
// 	int flag = 0;
// 	while (argv[1][i] == 32 || (argv[1][i] >= 9  && argv[1][i] <= 13))
// 		i++;
// 	while (argv[1][i] != '\0')
// 	{
// 		while(argv[1][i] != '\0' && argv[1][i] != 32 && !(argv[1][i] >= 9 && argv[1][i] <= 13))
// 		{
// 			if (flag == 1)
// 			{
// 				write(1,"   ", 3);
// 				flag = 0;
// 			}
// 			write(1, &argv[1][i], 1);
// 			i++;
// 		}
// 		while(argv[1][i] == 32 || (argv[1][i] >= 9  && argv[1][i] <= 13))
// 		{
// 			flag = 1;
// 			i++;
// 		}
// 	}
// 	write(1, "\n", 1);
// 	return 0;
// }


//	ES -4- -> torna!
// int uc_lc(char c, int  str_len)
// {
// 	char *uc = "0123456789ABCDEF";
// 	char *lc = "01234567890abcdef";
// 	int i = 0;
// 	while (i < str_len)
// 	{
// 		if(c == uc[i] || c == lc[i])
// 			return (i);
// 		i++;
// 	}
// 	return (-1);
// }


// int	ft_atoi_base(const char *str, int str_base)
// {
// 	int i = 0;
// 	int sign = 1;
// 	int result = 0;
// 	while (str[i] == 32 || str[i] >= 9 && str[i] <= 13)
// 		i++;
// 	if(str[i] == '+' || str[i] == '-')
// 	{
// 		if (str[i] == '-')
// 			sign *= -1;
// 		i++;
// 	}
// 	while(str[i] != '\0' && uc_lc(str[i], str_base) != -1)
// 	{
// 		result = result * str_base + uc_lc(str[i], str_base);
// 		i++;
// 	}
// 	return (result * sign);
// }


//	ES -5- 
// unsigned int lcm(unsigned int a, unsigned int b)
// {
// 	if(a == 0 || b == 0)
// 		return 0;
// 	unsigned int n = 0;
// 	if (a > b)
// 		n = a;
// 	else if (a < b)
// 		n = b;
// 	while (n > 0)
// 	{
// 		if (n % a == 0 && n % b == 0)
// 		{
// 			return n;
// 		}
// 		n++;
// 	}
// 	return 0;
// }

// int main()
// {
// 	unsigned int a = 256;
// 	unsigned int b = 94;
// 	printf("%d\n", lcm(a, b));
// 	return 0;
// }

#include "ft_list.h"
//	ES -6- -> torna!
// int ft_list_size(t_list *begin_list)
// {
// 	t_list *current = begin_list;
// 	int contatore = 0;
// 	while (current)
// 	{
// 		current = current->next;
// 		contatore++;
// 	}
// 	return (contatore);
// }

// int main()
// {
// 	t_list a;
// 	t_list b;
// 	t_list c;

// 	a.next = &b;
// 	b.next = &c;
// 	c.next = NULL;
// 	printf("%d\n", ft_list_size(&a));
// 	return 0;
// }


//	ES -7- -> torna!
// int *ft_range(int start, int end)
// {
// 	int *arr;
// 	int tmp;
// 	int i = 0;
// 	if (start < end)
// 		arr = malloc(((end - start) + 1) * sizeof(int));
// 	else if (start > end)
// 		arr = malloc(((start - end) + 1) * sizeof(int));
// 	else
// 		arr = malloc(sizeof(int));
// 	if (!arr)
// 		return 0;
// 	tmp = start;
// 	if (end > start)
// 		while(tmp <= end)
// 			arr[i++] = tmp++;
// 	else if (start > end)
// 		while (tmp >= end)
// 			arr[i++] = tmp--;
// 	else
// 		arr[i] = start;
// 	return arr;
// }


//	ES -8- -> torna!
// int *ft_rrange(int start, int end)
// {
// 	int tmp;
// 	int i = 0;
// 	int *arr;
// 	if (start > end)
// 		arr = malloc(((start - end) + 1) * sizeof(int));
// 	else if(start < end)
// 		arr = malloc(((end - start) + 1) * sizeof(int));
// 	else
// 		arr = malloc(sizeof(int));
// 	tmp = end;
// 	if (start > end)
// 		while (tmp <= start)
// 			arr[i++] = tmp++;
// 	if (start < end)
// 		while (tmp > start)
// 			arr[i++] = tmp--;
// 	else
// 		arr[i] = tmp;
// 	return (arr);
// }


// int main()
// {
// 	int *nums = ft_rrange(0, -2);
// 	int i = 0;
// 	while (i < 3)
// 	{
// 		printf("%d\n", nums[i]);
// 		i++;
// 	}
// 	return 0;
// }


//	ES -9-(hidenp) -> torna!
// int main(int argc, char *argv[])
// {
// 	if (argc != 3)
// 	{
// 		write (1, "\n", 1);
// 		return 0;
// 	}
// 	int i = 0;
// 	int j = 0;
// 	while (argv[2][j] != '\0')
// 	{
// 		if (argv[1][i] == argv[2][j])
// 			i++;
// 		if (argv[1][i] == '\0')
// 			break ;
// 		j++;
// 	}
// 	if (argv[1][i] == '\0')
// 		write (1, "1\n", 2);
// 	else
// 		write (1, "0\n", 2);
// 	return (0);
// }


//	ES -10- 
// int main(int argc, char *argv[])
// {
// 	if (argc == 1)
// 	{
// 		write(1, "0\n", 2);
// 		return 0;
// 	}
// 	else
// 		write(1, &argc, 1);
// 	return 0;
// }


//	ES -11- (paramsum) -> torna!
// void ft_putnbr(int n)
// {
// 	char c;
// 	if (n > 9)
// 		ft_putnbr(n / 10);
// 	c = (n % 10) + 48;
// 	write(1, &c, 1);
// }

// int main(int argc, char *argv[])
// {
// 	if (argc <= 1)
// 	{ 
// 		write(1, "0\n", 2);
// 		return 0;
// 	}
// 	int args = 1;
// 	while(argv[args])
// 	{ 
// 		args++;
// 	}
// 	args -= 1;
// 	ft_putnbr(args);
// 	write(1, "\n", 1);
// 	return 0;
// }


//	ES -12- (pgcd) -> torna! (il mio atoi ha un piccolo problema)
// int ft_atoi(const char *str)
// {
// 	int sign = 1;
// 	int result;
// 	int i = 0;
// 	if (!str)
// 		return 0;
// 	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
// 		i++;
// 	while (str[i] == '+' || str[i] == '-')
// 	{
// 		if (str[i] == '-')
// 			sign *= -1;
// 		i++;
// 	}
// 	while(str[i] >= '0' && str[i] <= '9')
// 	{ 
// 		result = result * 10 + (str[i] - 48);
// 		i++;
// 	}
// 	return(result * sign);
// }

// int main(int argc, char *argv[])
// {
// 	if (argc != 3)
// 	{
// 		write(1, "\n", 1);
// 		return 0;
// 	}
// 	int divisore = atoi(argv[1]);
// 	int dividendo = atoi(argv[2]);
// 	int tmp;
// 	if (divisore > dividendo)
// 		tmp = divisore;
// 	if (divisore < dividendo)
// 		tmp = dividendo;
// 	while (tmp > 0)
// 	{
// 		if (divisore % tmp == 0 && dividendo % tmp == 0)
// 		{
// 			printf("%d\n", tmp);
// 			return 0;
// 		}
// 		tmp--;
// 	}
// 	return 0;
// }


//	ES -13- (print hex) -> torna!
// int ft_atoi(const char *str)
// {
// 	int i = 0;
// 	int sign = 1;
// 	int result = 0;
// 	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
// 		i++;
// 	if(str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			sign = -1;
// 		i++;
// 	}
// 	while(str[i] >= '0' && str[i] <= '9')
// 	{ 
// 		result = result * 10 + (str[i] - 48);
// 		i++;
// 	}
// 	return (sign * result);
// }

// void ft_print_hex(int n)
// {
// 	char *base = "0123456789abcdef";
// 	if  (n > 16)
// 		ft_print_hex(n / 16);
// 	write(1, &base[n % 16], 1);
// }

// int main(int argc, char *argv[])
// {
// 	if (argc != 2)
// 	{
// 		write(1, "\n", 1);
// 		return 0;
// 	}
// 	//int i = 0;
// 	int conv = ft_atoi(argv[1]);
// 	write(1, "0x", 2);
// 	ft_print_hex(conv);
// 	write(1, "\n", 1);
// 	return 0;
// }


//	ES -14- (rstr capitalizer) -> da finire pk non ho voglia
// int main(int argc, char *argv[])
// {
// 	if (argc < 1)
// 	{ 
// 		write(1, "\n", 1);
// 		return 0;
// 	}
// 	int args = 1;
// 	int i = 0;
// 	while (argv[args])
// 	{
// 		while (argv[args][i] != '\0')
// 		{
// 			while ((argv[args][i] >= 'a' && argv[args][i] <= 'z') || (argv[args][i] >= 'A' && argv[args][i] <= 'Z'))
// 			{
// 				if (argv[args][i + 1] == 32 || (argv[args][i + 1] >= 9 && argv[args][i + 1] <= 13))
// 				argv[args][i] -= 32;
// 			}
// 			i++;
// 		}
// 		args++;
// 	}
// 	write(1, "\n", 1);
// 	return 0;
// }


//	ES -15- (tab mult) -> torna!
// int ft_atoi(const char *str)
// {
// 	int i = 0;
// 	int sign = 1;
// 	int result = 0;
// 	while(str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
// 		i++;
// 	if (str[i] == '+' || str[i] == '-')
// 	{
// 		if (str[i] == '-')
// 			sign = -1;
// 		i++; 
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		result = result * 10 + (str[i] - 48);
// 		i++;
// 	}
// 	return (result * sign);
// }

// void ft_putnbr(int n)
// {
// 	char c;
// 	if (n > 10)
// 		ft_putnbr(n / 10);
// 	c = (n % 10) + 48;
// 	write(1, &c, 1);
// }


// int main(int argc, char *argv[])
// {
// 	if (argc != 2)
// 	{
// 		write(1, "\n", 1);
// 		return 0;
// 	}
// 	int conv = ft_atoi(argv[1]);
// 	int n = 1;
// 	while(n < 10)
// 	{
// 		ft_putnbr(n);
// 		write(1, " x ", 3);
// 		ft_putnbr(conv);
// 		write(1, " = ", 3);
// 		ft_putnbr(n * conv);
// 		write(1, "\n", 1);
// 		n++;
// 	}
// 	return 0;
// }


//	- - - - LIVELLO 4 - - - -
//	ES -1- (flood fill)
// void fill_helper(char **tab, t_point size, int y, int x, char base)
// {
// 	if (y < 0 || y >= size.y)
// 		return ;
// 	else if (x < 0 || y >= size.x)
// 		return ;
// 	else if (tab[x][y] != base)
// 		return ;
// 	else
// 	{
// 		tab[y][x] = 'F';
// 		fill_helper(tab, size, y, x + 1, base);
//         fill_helper(tab, size, y, x - 1, base);
//         fill_helper(tab, size, y + 1, x, base);
//         fill_helper(tab, size, y - 1, x, base);
// 	}
// }
// void flood_fill(char **tab, t_point size, t_point begin)
// {
// 	char base = tab[begin.y, begin.x];
// 	fill_helper(tab, size, begin.y, begin.x, base);
// }

// char** make_area(char** zone, t_point size)
// {
// 	char** new;

// 	new = malloc(sizeof(char*) * size.y);
// 	for (int i = 0; i < size.y; ++i)
// 	{
// 		new[i] = malloc(size.x + 1);
// 		for (int j = 0; j < size.x; ++j)
// 			new[i][j] = zone[i][j];
// 		new[i][size.x] = '\0';
// 	}

// 	return new;
// }

// int main(void)
// {
// 	t_point size = {8, 5};
// 	char *zone[] = {
// 		"11111111",
// 		"10001001",
// 		"10010001",
// 		"10110001",
// 		"11100001",
// 	};

// 	char**  area = make_area(zone, size);
// 	for (int i = 0; i < size.y; ++i)
// 		printf("%s\n", area[i]);
// 	printf("\n");

// 	t_point begin = {7, 4};
// 	flood_fill(area, size, begin);
// 	for (int i = 0; i < size.y; ++i)
// 		printf("%s\n", area[i]);
// 	return (0);
// }


//	ES -2- (fprime)
// void is_prime(int n)
// {
// 	int i = 2;
// 	int first = 1;
// 	if (n == 1)
// 	{
// 		printf("1");
// 		return ;
// 	}
// 	while (n > 1)
// 	{
// 		if (n % i == 0)
// 		{
// 			if (!first)
// 				printf("*");
// 			printf("%d", i);
// 			n /= i;
// 			first = 0;
// 		}
// 		else
// 			n++;
// 	}
// }

// int main(int argc, char *argv[])
// {
// 	if(argc != 2)
// 	{
// 		write(1, "\n", 1);
// 		return 0;
// 	}
// 	int conv = atoi(argv[1]);
// 	is_prime(conv);
// 	printf("\n");
// 	return 0;
// }


//	ES -3- (ft itoa)
// int count_digits(int n)
// {
// 	int count = 0;
// 	if (n <= 0)
// 		count++;
// 	while (n)
// 	{
// 		n /= 10;
// 		count++;
// 	}
// 	return count;
// }

// char *ft_itoa(int n)
// {
// 	int len = count_digits;
// 	char *str = malloc(sizeof(char) * (len + 1));
// 	long nbr = n;
// 	if (!str)
// 		return 0;
// 	str[len] = '\0';
// 	while(nbr < 0)
// 	{
// 		str[0] = '-';
// 		nbr = -nbr;
// 	}
// 	if (nbr == 0)
// 		str[0] = '0';
// 	if (nbr > 0)
// 	{
// 		str[len - 1] = (nbr % 10) + 48;
// 		nbr /= 10;
// 		len--; 
// 	}
// 	return (str);
// }


//	ES -4- (ft list foreach) -> torna!
// void	ft_list_foreach(t_list *begin_list, void(*f)(void *))
// {
// 	t_list *list_ptr = begin_list;
// 	if (!begin_list || !f)
// 		return ;
// 	while (list_ptr)
// 	{
// 		(*f)(list_ptr->data);
// 		list_ptr = list_ptr->next;
// 	}
// }


//	ES -5- (ft list remove if) -> torna!
// void ft_list_remove_if(t_list **begin_list, void *data_ref, int(*cmp)())
// {
// 	t_list *current;
// 	t_list *tmp;
// 	while(*begin_list && (*cmp)((*begin_list)->data, data_ref) == 0)
// 	{
// 		tmp = *begin_list;
// 		*begin_list = (*begin_list)->next;
// 		free(tmp);
// 	}
// 	current = *begin_list;
// 	while(current && current->next)
// 	{
// 		if((*cmp)(current->next->data, data_ref) == 0)
// 		{
// 			tmp = current->next;
// 			current->next = tmp->next;
// 			free(tmp);
// 		}
// 		else
// 			current = current->next;
// 	}
// }


//	ES -6- (ft split) -> torna!
// int count_words(char *str)
// {
// 	int words = 0;
// 	int letters = 0;
// 	int i = 0;
// 	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
// 		i++;
// 	while(str[i])
// 	{
// 		while (str[i] != 32 && !(str[i] >= 9 && str[i] <= 13))
// 		{
// 			letters++;
// 			i++;
// 		}
// 		i++;
// 		words++;
// 	}
// 	return (words);
// }

// int count_letters(char *str, int i)
// {
// 	int letters = 0;
// 	while (str[i] && str[i] != 32 && !(str[i] >= 9 && str[i] <= 13))
// 	{
// 		letters++;
// 		i++;
// 	}
// 	return (letters);
// }

// char **ft_split(char *str)
// {
// 	int i = 0;
// 	int j = 0;
// 	int k;
// 	int len = 0;
// 	char **mem = malloc(sizeof(char *) * (count_words(str) + 1));
// 	if (!mem)
// 		return 0;
// 	while (str[i])
// 	{
// 		if (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
// 			i++;
// 		if(str[i])
// 		{
// 			len = count_letters(str, i);
// 			mem[j] = malloc(sizeof(char *) * (len + 1));
// 			if (!mem[j])
// 				return NULL;
// 			k = 0;
// 			while(k < len)
// 			{
// 				mem[j][k++] = str[i++];
// 			}
// 			mem[j][k] = '\0';
// 			j++;
// 		}
// 	}
// 	mem[j] = NULL;
// 	return mem;
// }

// int main()
// {
// 	char *str = "ciao mamma io sono camilla";
// 	printf("%d\n", count_words(str));
// 	return 0;
// }


//	ES -7- (rev wstr) -> torna!
// int main(int argc, char *argv[])
// {
// 	if (argc != 2)
// 	{
// 		write(1, "\n", 1);
// 		return 0;
// 	}
// 	int i = 0;
// 	int end = 0;
// 	while(argv[1][i])
// 		i++;
// 	i--;
// 	while (i >= 0)
// 	{
// 		while (i >= 0 && argv[1][i] != 32 && (argv[1][i] >= 9 && argv[1][i] <= 13))
// 			i--;
// 		end = i;
// 		while (i >= 0 && argv[1][i] != 32 && !(argv[1][i] >= 9 && argv[1][i] <= 13))
// 			i--;
// 		if (end >= 0)
// 		{
// 			write(1, &argv[1][i + 1], end - i);
// 			if (i > 0)
// 				write(1, " ", 1);
// 		}
// 	}
// 	write(1, "\n", 1);
// 	return 0;
// }