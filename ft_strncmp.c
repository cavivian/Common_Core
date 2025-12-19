/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:26:53 by cavivian          #+#    #+#             */
/*   Updated: 2025/12/10 17:18:09 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((char *)s1)[i] != '\0'
	&& ((char *)s1)[i] == ((char *)s2)[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	return (((char *)s1)[i] - ((char *)s2)[i]);
}

/*int	main()
{
	char	s1[] = "benvenuto";
	char	s2[] = "ciao";
	int	n = 2;
	
	printf("%d\n", ft_strncmp(s1, s2, n));
	return (0);
}*/	
