/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:26:27 by cavivian          #+#    #+#             */
/*   Updated: 2025/12/10 17:12:07 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*last_chr;

	last_chr = NULL;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			last_chr = ((char *)&str[i]);
		i++;
	}
	if ((char)c == 0)
		last_chr = ((char *)&str[i]);
	return (last_chr);
}

/*int	main()
{
	const char	str[] = "andiam";
	int	c = '\0';

	printf("%s\n", ft_strrchr(str, c));
}*/