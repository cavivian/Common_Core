/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 10:26:31 by cavivian          #+#    #+#             */
/*   Updated: 2026/05/21 14:20:55 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


//repeat_alpha
/*int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	int i = 0;
	while(argv[1][i] != '\0')
	{
		int lettere_da_stampare = 1;
		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			lettere_da_stampare = argv[1][i] - 'a' + 1;
		else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			lettere_da_stampare = argv[1][i] - 'A' + 1;
		while (lettere_da_stampare > 0)
		{
			write (1, &argv[1][i], 1);
			lettere_da_stampare--;
		}
		i++;
	}
	write(1, "\n", 1);
	return 0;
}*/

//ulstr
/*int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	int i = 0;
	while (argv[1][i] != '\0')
	{
		if(argv[1][i] >= 'a' && argv[1][i] <= 'z')
			argv[1][i] -= 32;
		else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			argv[1][i] += 32;
		write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return 0;
}*/

//rotone
/*int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	int i = 0;
	char tmp;
	while (argv[1][i] != '\0')
	{
		tmp = argv[1][i];
		if(argv[1][i] >= 'a' && argv[1][i] <= 'z') 
		{
			if(argv[1][i] == 'z')
				tmp = 'a';
			else
				tmp += 1;
		}
		if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
		{
			if(argv[1][i] == 'Z')
				tmp = 'A';
			else
				tmp += 1;
		}
		write(1, &tmp, 1);
		i++;
	}
	argv[1][i] = '\0';
	write(1, "\n", 1);
	return 0;
}*/

//inter
/*int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return 0;
	}
	int i = 0;
	int tabella[256] = {0};
	while (argv[2][i] != '\0')
	{
		tabella[(unsigned char)argv[2][i]] = 1;
		i++;
	}
	i = 0;
	while (argv[1][i] != '\0')
	{
		if (tabella[(unsigned char)argv[1][i]] == 1)
		{
			write(1, &argv[1][i], 1);
			tabella[(unsigned char)argv[1][i]] = 0;
		}
		i++;
	}
	write (1, "\n", 1);
	return 0;
}*/

//union
/*int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return 0;
	}
	char tabella[256] = {0};
	int i = 0;
	i = 0;
	while (argv[1][i] != '\0')
	{
		if (tabella[(unsigned char)argv[1][i]] == 0)
		{
			write(1, &argv[1][i], 1);
			tabella[(unsigned char)argv[1][i]] = 1;
		}
		i++;
	}
	i = 0;
	while (argv[2][i] != '\0')
	{
		if (tabella[(unsigned char)argv[2][i]] == 0)
		{
			write(1, &argv[2][i], 1);
			tabella[(unsigned char)argv[2][i]] = 1; // Se era già stata stampata nel passo 1, qui viene saltata!
		  }
		i++;
	}
	write (1, "\n", 1);
	return 0;
}*/


//wdmatch
/*int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return 0;
	}
	int i = 0;
	int j = 0;
	char tmp[1000];
	int k = 0;
	while (argv[2][j] != '\0')
	{
		if (argv[2][j] == argv[1][i])
		{
			tmp[k] = argv[2][j];
			k++;
			i++;
		}
		j++;
	}
	tmp[k] = '\0';
	if(argv[1][i] == '\0')
	{
		int n = 0;
		while (tmp[n] != '\0')
		{
			write(1, &tmp[n], 1);
			n++;
		}
	}
	write(1, "\n", 1);
	return 0;
}*/

//last_word
/*int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	int i = 0;
	char tmp[1000];
	int k = 0;
	while (argv[1][i] != '\0')
	{
		if ((argv[1][i] >= 9 && argv[1][i] <= 13) || argv[1][i] == 32)
			i++;
		while(argv[1][i] != '\0' && !((argv[1][i] >= 9 && argv[1][i] <= 13) || argv[1][i] == 32))
			{
				tmp[k] = argv[1][i];
				k++;
				i++;
			}
	}
	int n = 0;
	while(tmp[n] != '\0')
	{
		write(1, &tmp[n], 1);
		n++;
	}
	write(1, "\n", 1);
	return 0;
}*/


//rstr_capitalizer
int main(int argc, char *argv[])
{
	int ac = 1;
	if(argc == ac)
	{
		write(1, "\n", 1);
		return 0;
	}
	while(ac < argc)
	{
		int i = 0;
		while (argv[ac][i] != '\0')
		{
			if(argv[ac][i + 1] == '\0')
				argv[ac][i] -= 32;
			else
				argv[ac][i] += 32; 
			i++;
		}
		ac++;
	}
	write(1, "\n", 1);
	return 0;
}


























