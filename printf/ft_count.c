/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:26:05 by cavivian          #+#    #+#             */
/*   Updated: 2026/01/15 10:05:22 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* int	ft_count(int i)
{

} */
int	ft_puthexupp(unsigned int nb);

char	ft_conv(char *str)
{
	int		i;
	char	*n;

	i = ft_puthexupp(nb);
	n = ft_itoa(i);
	return (*n);
}

int	main(void)
{
	char	str[] = "1234";
	
	ft_conv(str);
	write (1, str, sizeof(str));
	return (0);
}