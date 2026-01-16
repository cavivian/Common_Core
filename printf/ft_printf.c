/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 08:45:37 by cavivian          #+#    #+#             */
/*   Updated: 2026/01/16 14:36:02 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

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
		ft_putper();
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
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
			ft_perc((char)format);
		i++;
	}
	return (0);
}
