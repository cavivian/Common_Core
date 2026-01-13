/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:30:38 by cavivian          #+#    #+#             */
/*   Updated: 2025/12/11 12:28:28 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*int	main(void)
{
	char const		s[] = "tripouille";
	unsigned int	start = 0;
	size_t			len = 42000;

	printf("%s\n", ft_substr(s, start, len));
	return (0);
}*/