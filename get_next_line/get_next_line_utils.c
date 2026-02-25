/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:02:29 by cavivian          #+#    #+#             */
/*   Updated: 2026/02/25 14:18:00 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	p = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!s1 && !s2)
		return (NULL);
	while (s1[i] != '\0')
		p[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		p[i++] = s2[j++];
	p[i] = '\0';
	if (s1)
		free (s1);
	return (p);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if(!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	if (!s)
		return (NULL);
	if (ft_strlen((char *)s) <= start)
	{
		p = malloc(1);
		p[0] = '\0';
		return (p);
	}
	i = 0;
	if (len > ft_strlen((char *)s) - start - 1)
		len = ft_strlen((char *)s) - start;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (i < len)
	{
		p[i] = ((char *)s)[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
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

char	*ft_strchr(const char *str, int p)
{
	while (*str != '\0')
	{
		if (*str == (char)p)
			return ((char *)str);
		str++;
	}
	if (*str == (char)p)
		return ((char *)str);
	return (NULL);
}

void	*ft_calloc(size_t num, size_t size)
{
	char	*str;
	size_t	i;

	if (size != 0 && num > __SIZE_MAX__ / size)
		return (NULL);
	str = malloc(num * size);
	if (!str)
		return (NULL);
	i = 0;
	while (i < num * size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
