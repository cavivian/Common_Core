/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:06:01 by cavivian          #+#    #+#             */
/*   Updated: 2025/12/11 08:45:31 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
	{
		j++;
	}
	if (n == 0)
		return (j);
	while (i < n - 1 && src[i] != '\0')
	{
		dest[i] = ((char *)src)[i];
		i++;
	}
	dest[i] = '\0';
	return (j);
}

/*int	main()
{
	char	dest[] = "pioggia";
	char	src[] = "e freddo";
	size_t	n = 5;
	
	printf("%s\n", ft_strlcpy(dest, src, n));
}*/
