/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:54:35 by cavivian          #+#    #+#             */
/*   Updated: 2025/12/10 14:34:13 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t	i;
	char	*j;

	j = ptr;
	i = 0;
	while (i < num)
	{
		j[i] = value;
		i++;
	}
	return (ptr);
}

/*int	main()
{
	char	ptr[] = "pioggia";
	int	value = 100;
	size_t	num = 3;
	unsigned char *str = ft_memset(ptr, value, num); 
	printf("%s\n", str);
	return (0); 
}*/
