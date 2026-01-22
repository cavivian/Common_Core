/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:31:45 by cavivian          #+#    #+#             */
/*   Updated: 2025/12/17 14:47:36 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	findwords(char *s, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			word++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (word);
}

static void	fre(char **split, int word)
{
	while (word > 0)
	{
		word--;
		free (split[word]);
	}
	free(split);
}

static int	alloc_words(char *s, char c, char **split)
{
	int	i;
	int	lenword;
	int	word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		lenword = 0;
		while (s[i + lenword] && s[i + lenword] != c)
			lenword++;
		split[word] = ft_calloc(lenword + 1, sizeof(char));
		if (!split[word])
		{
			fre(split, word);
			return (0);
		}
		word++;
		i += lenword;
	}
	return (1);
}

static void	countword(char *s, char c, char **split)
{
	int	i;
	int	word;
	int	letter;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		letter = 0;
		while (s[i + letter] && s[i + letter] != c)
		{
			split[word][letter] = s[i + letter];
			letter++;
		}
		split[word][letter] = '\0';
		i += letter;
		word++;
	}
	split[word] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**split;

	if (!s)
		return (NULL);
	i = findwords((char *)s, c);
	split = ft_calloc(i + 1, sizeof(char *));
	if (!split)
		return (NULL);
	if (!alloc_words((char *)s, c, split))
		return (NULL);
	countword((char *)s, c, split);
	return (split);
}

/*int	main(void)
{
	char const	s[] = "  tripouille  42  ";
	char		c = ' ';
	char 		**split = ft_split(s, c);

	printf("%s\n", split[0]);
	if(split[1][0] == '\0')
		printf("ciao"); 
	printf("%s\n", split[1]);
	printf("%s\n", split[2]);
	printf("%s\n", split[3]);
	int i = 0;
	while(i < 4)
	{
		free (split[i]);
		i++;
	}
	free (split);
	return (0);
}*/
