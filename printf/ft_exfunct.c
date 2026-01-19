/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exfunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:55:07 by cavivian          #+#    #+#             */
/*   Updated: 2026/01/19 13:47:01 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
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
	return (nb);
}

int	ft_putnullpoint(void *c) //%p prints the void* argument in base 16
{
	unsigned long		p;

	p = (unsigned long)c;
	write (1, "0x", 2);
	ft_puthexlow(p);
	return (p);
}
