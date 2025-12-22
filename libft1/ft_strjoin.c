/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:30:57 by cavivian          #+#    #+#             */
/*   Updated: 2025/12/11 15:01:33 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*int	main(void)
{
	char const	s1[] = "piove";
	char const	s2[] = "col sole";

	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
}*/