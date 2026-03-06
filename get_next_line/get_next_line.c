/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:02:07 by cavivian          #+#    #+#             */
/*   Updated: 2026/02/27 09:44:43 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*endivide(char *str)
{
	int		len;
	char	*tmp;

	len = 0;
	tmp = NULL;
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	if (str[0] == '\0' || !str || !str[len])
	{
		free (str);
		return (NULL);
	}
	if (ft_strchr(str, '\n'))
	{
		tmp = ft_strdup(ft_strchr(str, '\n') + 1);
	}
	else if (!ft_strchr(str, '\n'))
		tmp = ft_strdup(str);
	free (str);
	return (tmp);
}

char	*startdivide(char *str)
{
	int		len;
	char	*tmp;
	int		i;

	len = 0;
	i = 0;
	if (!str[0])
		return (NULL);
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	tmp = malloc(len + 2);
	if (!tmp)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		tmp[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		tmp[i++] = '\n';
	tmp[i] = '\0';
	return (tmp);
}

char	*ciclo(char *str, int fd)
{
	char		*m;
	int			byte;

	byte = 1;
	m = malloc(BUFFER_SIZE + 1);
	if (!m)
		return (NULL);
	while (byte > 0)
	{
		byte = read(fd, m, BUFFER_SIZE);
		if (byte == -1)
			return (free (m), free (str), NULL);
		m[byte] = '\0';
		if (!str)
			str = ft_calloc(1, sizeof(char));
		str = ft_strjoin(str, m);
		if (ft_strchr(str, '\n') || byte < BUFFER_SIZE)
			break ;
	}
	free(m);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free (str);
		return (NULL);
	}
	str = ciclo(str, fd);
	if (!str)
		return (NULL);
	tmp = startdivide(str);
	str = endivide(str);
	return (tmp);
}

/*  int	main()
{
	int	fd;
	char	*str;
	
	fd = open("file.txt", O_RDONLY);
	while (str = get_next_line(1000))
	{
		printf("%s", str);
		free (str);
	}
	free (str);
	return (0);
} */