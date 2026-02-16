/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:02:07 by cavivian          #+#    #+#             */
/*   Updated: 2026/02/14 15:33:26 by camilla          ###   ########.fr       */
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
			*str = ft_strjoin(*str, ft_substr(buffer, 0, i + 1));
			buffer = ft_substr(buffer, i + 1, ft_strlen(buffer) - i - 1);
			return (*str);
		}
		else if (buffer[i] == '\0')
			return (NULL);
	}
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*m;
	int			i;

	m = malloc(BUFFER_SIZE);
	if (!m)
		return (NULL);
	i =read(fd, m, BUFFER_SIZE);
	if (i == 0)
		return (NULL);
	contrnwline(m, &str);
	free(m);
	if (str)
		return (str);
	else
		return (NULL);
}
