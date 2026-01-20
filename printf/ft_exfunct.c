/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exfunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:55:07 by cavivian          #+#    #+#             */
/*   Updated: 2026/01/20 15:49:34 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb < 10)
	{
		ft_putchar(nb + '0');
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	return (count_intlen(nb));
}

//%X prints a number in hexadecimal uppercase format
int	ft_puthexupp(unsigned int nb)
{
	if (nb >= 16)
	{
		ft_puthexupp(nb / 16);
	}
	if ((nb % 16) < 10)
		ft_putchar(48 + (nb % 16));
	else
		ft_putchar('A' + ((nb % 16) - 10));
	return (nb);
}
unsigned long	suca(unsigned long num)
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
int	ft_putunsnbr(unsigned int nb) //%u prints an unsigned number in base 10
{
	if (nb < 10)
	{
		ft_putchar(nb + '0');
	}
	else
	{
		ft_putunsnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	return (suca(nb));
}

int	ft_putnullpoint(void *c) //%p prints the void* argument in base 16
{
	unsigned long		p;
	int n;

	n = 0;
	p = (unsigned long)c;
	write (1, "0x", 2);
	n = ft_puthexlow(p, 'x');
	return (n + 2);
}
