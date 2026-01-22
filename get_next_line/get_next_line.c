/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:02:07 by cavivian          #+#    #+#             */
/*   Updated: 2026/01/22 17:14:18 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		i;
	char	*buffer;
	char	*m;

	i = 0;
	m = malloc(ft_strlen(buffer) + 1);
	if (!m)
		return (NULL);
	while (buffer[i] != '\0')
	{
		write(1, &buffer[i], sizeof(buffer));
		write(1, "\n", 1);
		read(0, &buffer [i], sizeof(buffer));
		i++;
	}
	free(m);
	return (buffer);
}
