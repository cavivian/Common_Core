/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:30:05 by cavivian          #+#    #+#             */
/*   Updated: 2025/12/04 11:22:49 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*a;
	int		i;

	i = 0;
	a = malloc(ft_strlen((char *)s) + 1);
	while (s[i])
	{
		a[i] = s[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

/*int	main(void)
{
	const char	s[] = "pioggia";
	char		*p = ft_strdup(s);

	printf("%s\n", ft_strdup(s));
	return (0);
	free (p);
}*/