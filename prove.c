#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


//	ES-1- (first word) -> torna!
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


//  ES -7- -> tecnicamente torna, non so se l'ho testata bene
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
//     char *str = "ciao mamma";
//     printf("%s", ft_strdup(str));
//     return 0;
// }


//  ES -8- ->  non funziona, da ragionarci per bene
// char	*ft_strpbrk(const char *s1, const char *s2)
// {
//     int i = 0;
//     int j = 0;
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
//     // 	printf("%s\n", ft_strpbrk(s1, s2));
//     // printf("%s\n", strpbrk(s1, s2));
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
// 	printf("%d", is_power_of_2(n ));
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
// 	int i = 0;
// 	unsigned char bit;
// 	while(i < 8)
// 	{
// 		bit = ((octet >> i & 1) + '0');
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
// 	int i = 7;
// 	unsigned char bit;
// 	while (i--)
// 	{
// 		bit = ((octet >> i & 1) + '0');
// 		write(1, &bit, 1);
// 	}
// 	return (0);
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

// }


//	ES -16- (union)
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	int i = 0;
	int j = 0;
	char tmp;
	while(argv[1][i] != '\0')
	{
		while(argv[2][j] != '\0')
		{
			if(argv[1][i] == argv[2][j])
			{
				tmp = argv[1][i];
				write(1, &tmp, 1);
			}
			else if(argv[1][i] != argv[2][j] && argv[2][j] != tmp)
			{
				
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
	return 0;
}