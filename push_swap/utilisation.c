/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilisation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 09:12:04 by cavivian          #+#    #+#             */
/*   Updated: 2026/04/22 11:45:11 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

t_node	*ft_lstlast(t_node *lst)
{
	while (lst != NULL)
	{
		if(!lst)
			return(NULL);
		while (lst->next != NULL)
			lst = lst->next;
		return(lst);
	}
	return (0);
}
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
