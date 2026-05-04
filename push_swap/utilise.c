/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:49:03 by cavivian          #+#    #+#             */
/*   Updated: 2026/04/29 10:36:57 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	p = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!s1 || !s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		p[i + j] = s2[j];
		j++;
	}
	p[i + j] = '\0';
	return (p);
}

char	*join_args(int argc, char **argv)
{
	char	*tmp;
	char	*s1;
	int		i;

	i = 1;
	s1 = ft_strdup("");
	while (i < argc)
	{
		tmp = ft_strjoin(s1, argv[i]);
		free(s1);
		s1 = ft_strjoin(tmp, " ");
		free(tmp);
		i++;
	}
	return (s1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*a;
	int		i;

	i = 0;
	a = malloc(ft_strlen((char *)s) + 1);
	while (s[i])
	{
		a[i] = s[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

void	conver(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] == '\t' || str[j] == '\n'
			|| str[j] == '\v' || str[j] == '\f' || str[j] == '\r')
			str[j] = ' ';
		j++;
	}
}
