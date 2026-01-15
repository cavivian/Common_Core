/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 08:45:37 by cavivian          #+#    #+#             */
/*   Updated: 2026/01/15 08:43:56 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_perc(char c, va_list args)
{
	if (c == 'c')
		ft_putchar(va_arg(args, char));
	else if (c == 'd' || c == 'i')
		ft_putint(va_arg(args, int));
	else if (c == 'p')
		ft_putnullpoint(va_arg(args, void *));
	else if (c == 'x')
		ft_puthexlow(va_arg(args, unsigned int));
	else if (c == 'X')
		ft_puthexupp(va_arg(args, unsigned int));
	else if (c == '%')
		ft_putper(va_arg(args, char));
	else if (c == 's')
		ft_putstr(va_arg(args, char *));
	else if (c == 'u')
		ft_putunsnbr(va_arg(args, unsigned int));
	va_end(args);
}

//qui devo usare le variabili: va_list, va_start, va_arg, va_copy e va_end.
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			ft_perc(c, args);
		i++;
	}
}
