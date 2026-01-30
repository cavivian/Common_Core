/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:02:07 by cavivian          #+#    #+#             */
/*   Updated: 2026/01/26 10:51:58 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	controllen(int i)
{

}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	int			i;
	char		*buffer;
	char		*m;
	int			fd;

	i = 0;
	fd = 1;
	m = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!m || !str)
		return (NULL);
	str = buffer;
	while (fd > 0 && str[i])
	{
		controllen(i);
		read(0, buffer[i], BUFFER_SIZE + 1);
		write(1, &buffer[i], BUFFER_SIZE + 1);
		write(1, "\n", 1);
		i++;
	}
	free(m);
	return (str);
}
