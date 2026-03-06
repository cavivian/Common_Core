/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 08:45:37 by cavivian          #+#    #+#             */
/*   Updated: 2026/02/07 12:07:08 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count(char a, va_list *ap)
{
	int		count;

	count = 0;
	if (a == 'c')
	{
		ft_putchar((char)va_arg(*ap, int));
		count = 1;
	}
	else if (a == '%')
	{
		ft_putchar('%');
		count++;
	}
	else if (a == 's')
		count = ft_putstr(va_arg(*ap, char *));
	else if (a == 'x' || a == 'X')
		count = ft_puthexlow(va_arg(*ap, unsigned int), a);
	else if (a == 'd' || a == 'i')
		count = ft_putnbr(va_arg(*ap, int));
	else if (a == 'p')
		count = ft_putnullpoint(va_arg(*ap, void *));
	else if (a == 'u')
		count = ft_putunsnbr(va_arg(*ap, unsigned int));
	return (count);
}

//qui devo usare le variabili: va_list, va_start, va_arg, va_copy e va_end.
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	count = 0;
	va_start(ap, format);
	i = 0;
	if (!format)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			count += ft_count(format[i + 1], &ap);
			i++;
		}
		else if (format[i] != '%')
		{
			ft_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}

/* int	main(void)
{
	printf("%d\n", ft_printf(" NULL %s NULL \n", NULL));
	//printf("%d\n", printf(" NULL %s NULL ", NULL));
	return (0);
} */
