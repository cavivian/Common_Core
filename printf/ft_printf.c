/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 08:45:37 by cavivian          #+#    #+#             */
/*   Updated: 2026/01/19 14:48:41 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_perc(char c, va_list *ap)
{
	if (c == 'c')
		ft_putchar((char)va_arg(*ap, int));
	else if (c == 'd' || c == 'i')
		ft_putint(va_arg(*ap, int));
	else if (c == 'p')
		ft_putnullpoint(va_arg(*ap, void *));
	else if (c == 'x')
		ft_puthexlow(va_arg(*ap, unsigned int));
	else if (c == 'X')
		ft_puthexupp(va_arg(*ap, unsigned int));
	else if (c == '%')
		ft_putper();
	else if (c == 's')
		ft_putstr(va_arg(*ap, char *));
	else if (c == 'u')
		ft_putunsnbr(va_arg(*ap, unsigned int));
	return (0);
}

//qui devo usare le variabili: va_list, va_start, va_arg, va_copy e va_end.
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	//int		count;

	va_start(ap, format);
	i = 0;
	if (!format)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_perc(format[i + 1], &ap);
			i += 2;
			//count = ft_perc(format[i], &ap);
		}
		else
		{
			ft_putchar(format[i]);
			i++;
		}
	}
	va_end(ap);
	return (i);
}

/* int	main(void)
{
	printf("%d\n", ft_printf("%s\n", "ciaodfhd"));
	printf("%d\n", printf("%s\n", "ciaodfhd"));
	return (0);
} */
