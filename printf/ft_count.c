/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:26:05 by cavivian          #+#    #+#             */
/*   Updated: 2026/01/16 14:38:14 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* int	ft_count(int i)
{
	
} */


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

char	*ft_itoahex(long num)
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
		s[i] = num % 16 + 48;
		num /= 16;
		i--;
	}
	return (s);
}

char	ft_conv(int b)
{
	int		i;
	char	*n;

	i = ft_puthexupp(b);
	n = ft_itoahex(i);
	return (*n);
}

/* int	main(void)
{
	//char	str[] = "1234";
	int	b = 23;

	ft_conv(b);
	return (0);
} */