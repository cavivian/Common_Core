/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:02:07 by cavivian          #+#    #+#             */
/*   Updated: 2026/01/23 15:55:58 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	int			i;
	char		*buffer;
	char		*m;

	i = 0;
	m = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!m)
		return (NULL);
	while (buffer[i] != '\n')
	{
		read(0, buffer[i], BUFFER_SIZE);
		write(1, &buffer[i], BUFFER_SIZE);
		write(1, "\n", 1);
		i++;
	}
	free(m);
	return (str);
}
