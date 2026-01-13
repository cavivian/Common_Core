/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:27:30 by cavivian          #+#    #+#             */
/*   Updated: 2025/12/05 12:13:14 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buffer, int c, size_t count)
{
	unsigned int	i;

	i = 0;
	if (count == 0)
		return (NULL);
	while (i < count)
	{
		if ((unsigned char)c == ((const unsigned char *)buffer)[i])
			return ((void *)buffer + i);
		i++;
	}
	return (NULL);
}

/*int	main()
{
	const unsigned char	buffer[] = "piggiaghiovvhc;";
	int	c = 111;
	size_t	count = 5;

	printf("%s\n", (unsigned char *)ft_memchr(buffer, c, count));
	return (0);
}*/
