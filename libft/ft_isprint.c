/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:53:51 by cavivian          #+#    #+#             */
/*   Updated: 2025/12/12 17:09:47 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	c = (unsigned char)c;
	if (c < 0)
		return (0);
	if ((c >= 0 && c <= 31)
		|| (c == 127))
		return (0);
	return (1);
}

/*int	main(void)
{
	printf("%d\n", ft_isprint(-10));
}*/
