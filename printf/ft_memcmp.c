/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:27:51 by cavivian          #+#    #+#             */
/*   Updated: 2025/12/10 16:39:29 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buffer1, const void *buffer2, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (((const unsigned char *)buffer1)[i]
		== ((const unsigned char *)buffer2)[i])
			i++;
		else
			return (((const unsigned char *)buffer1)[i]
				- ((const unsigned char *)buffer2)[i]);
	}
	return (0);
}

/*int	main()
{
	const char	buffer1[] = "pioggia";
	const char	buffer2[] = "sile";
	size_t	count = 2;
	
	printf("%d\n", ft_memcmp(buffer1, buffer2, count));
	return (0);
}*/