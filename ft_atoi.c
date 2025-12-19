/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:28:34 by cavivian          #+#    #+#             */
/*   Updated: 2025/12/12 16:16:45 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
		if (!(str[i] >= 48 && str[i] <= 57))
			return (0);
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (((char *)str)[i] - 48);
		i++;
	}
	return (result * sign);
}
/*int	main()
{
	printf("%d\n", ft_atoi("--djd638946+-+++---c"));
	return (0);
}*/
