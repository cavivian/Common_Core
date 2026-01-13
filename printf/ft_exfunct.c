/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exfunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:55:07 by cavivian          #+#    #+#             */
/*   Updated: 2026/01/13 14:10:59 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	ft_putchars(char c)
{
	write(1, &c, 1);
} */

/* void	ft_putnbr(int nb)
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
} */
//%X prints a number in hexadecimal uppercase format
/* int	ft_puthexupp(unsigned int nb)
{
	if (nb >= 16)
	{
		ft_puthex(nb / 16);
	}
	if ((nb % 16) < 10)
		ft_putchars(48 + (nb % 16));
	else
		ft_putchars('A' + ((nb % 16) - 10));
} */

/* int	ft_putunsnbr(unsigned int nb) //%u prints an unsigned number in base 10
{
	if (nb < 10)
	{
		ft_putchars(nb + '0');
	}
	else
	{
		ft_putunsnbr(nb / 10);
		ft_putchars(nb % 10 + '0');
	}
} */
void	ft_putchar(char c) //%c prints a single character
{
	write(1, &c, 1);
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
}

int	ft_putnullpoint(void *c) //%p prints the void* argument in base 16
{
	unsigned long		p;

	p = (unsigned long)c;
	write (1, "0x", 2);
	ft_puthexlow(p);
	return ;
}

/* int	main(void)
{
	void	*s = "hgfhgfhgf";

	ft_putnullpoint(s);
	printf("\n");
	/* printf("%d", printf("%p\n", s)); 
	return (0);
} */
