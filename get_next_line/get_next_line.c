/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:02:07 by cavivian          #+#    #+#             */
/*   Updated: 2026/02/06 15:39:34 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	controllen(char *buffer, int buffer_size)
{
	int	i;

	i = ft_strlen(buffer);
	while (buffer[i] < BUFFER_SIZE)
	{
		read(0, buffer[i], BUFFER_SIZE);
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	int			fd;
	static char	*str;
	char		*buffer;
	int			i;
	char		*m;

	fd = 0;
	str = NULL;
	i = 0;
	m = malloc(buffer);
	if (!str || !buffer || !m)
		return (NULL);
	while (buffer[i] != '\0')
	{
		
	}
	free(m);
}