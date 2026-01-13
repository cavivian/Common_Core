/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:25:57 by cavivian          #+#    #+#             */
/*   Updated: 2025/12/10 16:53:42 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int p)
{
	while (*str != '\0')
	{
		if (*str == (char)p)
			return ((char *)str);
		str++;
	}
	if (*str == (char)p)
		return ((char *)str);
	return (NULL);
}

/*int	main()
{
	char	str[] = "andiamo";
	int	p = 100;
	
	printf("%s\n", ft_strchr( str, p));
}*/
