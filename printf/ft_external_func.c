/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_external_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 09:33:39 by cavivian          #+#    #+#             */
/*   Updated: 2026/01/16 14:15:37 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdarg.h>

void	ft_putchar(char c) //%c prints a single character
{
	write(1, &c, 1);
}

void	ft_putstr(char *str) //%s prints a string
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[1], 1);
		i++;
	}
}

int	ft_putint(int n) //%d e %i prints a decimal and integer in base 10
{
	ft_putnbr(n);
	return (n);
}

int	ft_putper(void) //%% prints a percent sign
{
	char	c;

	c = 37;
	write (1, &c, 1);
	return (c);
}

//%x prints a number in hexadecimal lowercase format
int	ft_puthexlow(unsigned int nb)
{
	if (nb >= 16)
	{
		ft_puthexlow(nb / 16);
	}
	if ((nb % 16) < 10)
		ft_putchar(48 + (nb % 16));
	else
		ft_putchar('a' + ((nb % 16) - 10));
	return (nb);
}

/* int	main(void)
{
	int	n;

	n = 473;
	ft_puthexlow(n);
	write (1, &n, 1);
	return (0);
} */
