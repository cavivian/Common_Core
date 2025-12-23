/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_external_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 09:33:39 by cavivian          #+#    #+#             */
/*   Updated: 2025/12/23 10:54:02 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	ft_putchar(char c)
{
	write(1, &c, 1);
}*/

/*void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[1], 1);
		i++;	
	}
}*/

void	ft_putint(int n)
{
	while (n >= 0 && n <= 0)
	{
		int	i;

		n = n / 10;
		i = n % 10;
		write (1, (char *)&i, sizeof(i));
		n++;
	}
}

/*void	ft_putper()
{
	char	c;

	c = 37;
	write (1, &c, 1);
}*/

int	main()
{
	int	n;
	
	n = 14;
	ft_putint(n);
	write (1, &n, 1);
	return (0);
}