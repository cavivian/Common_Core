/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:02:07 by cavivian          #+#    #+#             */
/*   Updated: 2026/02/16 14:06:26 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*contrnwline(char *buffer, char **str)
{
	int	i;

	i = 0;
	if(buffer[i] == '\0')
			return (NULL);
	while (buffer[i] != '\0')
	{
		while (buffer[i] != '\n' && buffer[i] != '\0')
			i++;
		if (buffer[i] == '\n')
		{
			*str = ft_strjoin(*str, ft_substr(buffer, 0, i + 1)); // i+1 = byte subito dopo '\n'
			buffer = ft_substr(buffer, i + 1, ft_strlen(buffer) - i - 1); // -i -1 = da' la lunghezza del resto della stringa senza contare '\n'
			return (*str);
		}
		else if (buffer[i] == '\0')
		{
			*str = ft_strjoin(*str, ft_substr(buffer, 0, i));
			return (*str);
		}
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*m;
	int			i;

	m = malloc(BUFFER_SIZE + 1);
	if (!m)
		return (NULL);
	i =read(fd, m, BUFFER_SIZE);
	m[i] = '\0';
	while (!*str || (int)ft_strlen(str) - 1 != '\n')
	{
		i = read(fd, m, BUFFER_SIZE);
		if (i == 0)
			break;
		m[i] = '\0';
		contrnwline(m, &str);
	}
	if (i == 0)
		return (NULL);
	contrnwline(m, &str);
	free(m);
	if (str)
		return (str);
	else
		return (NULL);
}

int	main()
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
}