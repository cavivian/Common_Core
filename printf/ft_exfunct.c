/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exfunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:55:07 by cavivian          #+#    #+#             */
/*   Updated: 2026/01/07 13:21:35 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchars(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchars('-');
		nb = -nb;
	}
	if (nb < 10)
	{
		ft_putchars(nb + '0');
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putchars(nb % 10 + '0');
	}
}

void	ft_puthexupp(unsigned int nb)
{
	if (nb >= 16)
	{
		ft_puthex(nb / 16);
	}
	if ((nb % 16) < 10)
		ft_putchar(48 + (nb % 16));
	else
		ft_putchar('A' + ((nb % 16) - 10));
}

void	ft_putnbr(unsigned int nb)
{
	if (nb < 10)
	{
		ft_putchars(nb + '0');
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putchars(nb % 10 + '0');
	}
}