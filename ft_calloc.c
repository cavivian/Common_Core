/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:29:15 by cavivian          #+#    #+#             */
/*   Updated: 2025/12/11 10:41:37 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*int	main()
{
	size_t	num = 4;
	char	*b = ft_calloc(num, 1);
	size_t i = 0;
	while(i < 5)
	{
		if (b[i] == '\0')
			printf("\\0\n");
		i++;		
	}
	return (0);
}*/