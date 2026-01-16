/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:32:04 by cavivian          #+#    #+#             */
/*   Updated: 2026/01/16 14:38:51 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_intlen(int num)
{
	int	len;

	len = 0;
	if (num <= 0)
		len++;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(long num)
{
	char	*s;
	int		i;
	int		len;

	len = count_intlen(num);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	i = len - 1;
	if (num < 0)
	{
		s[0] = '-';
		num *= -1;
	}
	if (num == 0)
		s[i] = '0';
	while (num > 0)
	{
		s[i] = num % 10 + 48;
		num /= 10;
		i--;
	}
	return (s);
}

/*int	main(void)
{
	int		num = -42;

	printf("%s\n", ft_itoa(num));
	return (0);
}*/