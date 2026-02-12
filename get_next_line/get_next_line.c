/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:02:07 by cavivian          #+#    #+#             */
/*   Updated: 2026/02/11 21:34:47 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	controllen(char *buffer, int buffer_size)
{
	int	i;
	char	*m;
	
	m = malloc(buffer_size);
	if (!m)
		return (-1);
	i = ft_strlen(buffer);
	while (buffer[i] < BUFFER_SIZE)
	{
		read(0, buffer[i], BUFFER_SIZE);
		i++;
	}
	return (i);
}

char	contrnwline( char *buffer, int buffer_size)
{
	int				i;
	char			*m;
	static  char	*str;
	
	if (!m)
		return (0);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		{
			str = ft_strjoin(str, ft_substr(buffer, 0, i + 1));
			buffer = ft_substr(buffer, i + 1, ft_strlen(buffer) - i - 1);
			m = malloc(sizeof (str)); 
		}
	return (str);
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