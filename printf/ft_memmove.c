/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:13:56 by cavivian          #+#    #+#             */
/*   Updated: 2025/12/05 12:16:49 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned int	i;

	if (dest < src)
	{
		i = 0;
		while (i < count)
		{
			((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		i = count;
		while (i > 0)
		{
			((unsigned char *)dest)[i - 1] = ((const unsigned char *)src)[i -1];
			i--;
		}
	}
	return (dest);
}

/*int	main()
{
	char	dest[] = "pioggia";
	const char	src[] = "sole";
	size_t	count = 3;

	printf("%s\n", (char *)ft_memmove(dest, src, count));
	return (0);
}*/