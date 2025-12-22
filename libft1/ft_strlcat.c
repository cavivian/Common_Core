/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:24:50 by cavivian          #+#    #+#             */
/*   Updated: 2025/12/19 16:50:41 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	len;
	size_t	a;
	size_t	b;

	len = ft_strlen((char *)src) + ft_strlen((char *)dest);
	a = ft_strlen((char *)dest);
	b = 0;
	if (n <= a)
		return (n + ft_strlen(src));
	while (((char *)src)[b] && (b + a + 1) < n)
	{
		dest[a + b] = src[b];
		b++;
	}
	dest[a + b] = '\0';
	return (a + ft_strlen(src));
}

/*int	main()
{
	char	dest[50] = "andiamo";
	const char	src[] = "ahdjgewgw";
	int	n = 3;
	
	printf("%s\n", ft_strlcat(dest, src, n));
	return (0);
}*/
