/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:31:18 by cavivian          #+#    #+#             */
/*   Updated: 2025/12/17 14:48:44 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	top(char const *s1, char const *set)
{
	int	i;

	i = 0;
	if (!s1 || !set)
		return (0);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static int	bottom(char const *s1, char const *set)
{
	int		i;

	if (!s1 || !set)
		return (0);
	i = ft_strlen((char *)s1) - 1;
	while (i >= 0 && ft_strchr(set, s1[i]))
	{
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*p;
	int		c;
	int		t;

	t = top(s1, set);
	c = bottom(s1, set);
	i = 0;
	if (!s1 || !set)
		return (NULL);
	c = bottom(s1, set);
	if (t > c)
		p = malloc(1);
	else
		p = malloc(c - t + 2);
	if (!p)
		return (NULL);
	while (t <= c)
		p[i++] = s1[t++];
	p[i] = '\0';
	return (p);
}

/*int	main(void)
{
	char const	s1[] = "andiamo";
	char const	set[] = "a";

	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}*/