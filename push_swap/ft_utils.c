/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:13:32 by cavivian          #+#    #+#             */
/*   Updated: 2026/01/21 11:42:00 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_intlen(long num)
{
	int	len;

	len = 0;
	if (num <= 0)
	{
		num *= -1;
		len++;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

void	*ft_calloc(size_t num, size_t size)
{
	char	*str;
	size_t	i;

	if (size != 0 && num > __SIZE_MAX__ / size)
		return (NULL);
	str = malloc(num * size);
	if (!str)
		return (NULL);
	i = 0;
	while (i < num * size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

int	ft_itoa(long num)
{
	char	*s;
	int		i;
	int		len;

	len = count_intlen(num);
	s = ft_calloc((len + 1), sizeof (char));
	if (!s)
		return (0);
	i = len - 1;
	if (num < 0)
	{
		s[0] = '-';
		num *= -1;
	}
	if (num == 0)
		s[i] = '0';
	while (num > 0)
	{
		s[i] = num % 10 + 48;
		num /= 10;
		i--;
	}
	ft_putstr(s);
	return (len);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
