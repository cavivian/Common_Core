/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:02:07 by cavivian          #+#    #+#             */
/*   Updated: 2026/02/13 16:41:42 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*contrnwline(char *buffer, int buffer_size,char **str, char **m)
{
	int				i;

	i = 0;
	while (buffer[i] != '\0')
	{
		while (buffer[i] != '\n' && buffer[i] != '\0')
		{
			i++;
		}
		return (NULL);
		if (buffer[i] == '\n')
		{
			*str = ft_strjoin(*str, ft_substr(buffer, 0, i + 1));
		}
	}
	return (*str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buffer;
	int			i;
	char		*m;
	
	i = 0;
	m = malloc(BUFFER_SIZE);
	if (!str || !buffer || !m)
		return (NULL);
	read(fd, &buffer, BUFFER_SIZE);
	while (buffer[i] != '\0')
	{
		while (buffer[i] != '\n' && buffer[i] != '\0')
			i++;
		if (buffer[i] == '\n')
		{			str = ft_strjoin(str, ft_substr(buffer, 0, i + 1));
			buffer = ft_substr(buffer, i + 1, ft_strlen(buffer) - i - 1);
			return (str);
		}
	}
	free(m);
}
