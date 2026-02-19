/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:02:07 by cavivian          #+#    #+#             */
/*   Updated: 2026/02/19 09:40:33 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*contrnwline(char *buffer, char **str)
{
	int	i;
	char *tmp;
	char *vol;

	i = 0;
	if (buffer[i] == '\0')
		return (NULL);
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			tmp = *str;
			vol = ft_substr(buffer, 0, i + 1);
			buffer = ft_strjoin(buffer, tmp);
			
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*m;
	int			i;

	m = malloc(BUFFER_SIZE + 1);
	if (!m)
		return (NULL);
	while (!str || (str && ft_strlen(str) > 0 && str[ft_strlen(str) - 1] != '\n'))
	{
		i = read(fd, m, BUFFER_SIZE);
		if (i == 0)
			break;
		m[i] = '\0';
		contrnwline(m, &str);
	}
	if (i == 0 && !str)
		return (str);
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