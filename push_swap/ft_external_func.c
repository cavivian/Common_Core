/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_external_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 09:33:39 by cavivian          #+#    #+#             */
/*   Updated: 2026/01/21 13:32:17 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c) //%c prints a single character
{
	write(1, &c, 1);
}

int	ft_putstr(char *str) //%s prints a string
{
	int	i;

	i = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (ft_strlen(str));
}

int	ft_putint(int n) //%d e %i prints a decimal and integer in base 10
{
	ft_putnbr(n);
	return (n);
}

//%x prints a number in hexadecimal lowercase format
int	ft_puthexlow(unsigned long nb, char a)
{
	char	c;
	int		n;

	c = 'a';
	n = 0;
	if (a == 'X')
		c -= 32;
	if (nb >= 16)
	{
		n += ft_puthexlow(nb / 16, a);
	}
	if ((nb % 16) < 10)
		ft_putchar(48 + (nb % 16));
	else
		ft_putchar(c + ((nb % 16) - 10));
	return (n + 1);
}
