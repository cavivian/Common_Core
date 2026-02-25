/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:02:07 by cavivian          #+#    #+#             */
/*   Updated: 2026/02/25 14:59:06 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//heap permette di allocare memoria la cui dimensione e' nota solo durante il runtime della funzione e mantiene i dati anche dopo la fine della funzione che li ha creati

char	*endivide(char *str) // duplica la stringa da dopo la \n fino a \0
{
	int		len;
	char	*tmp;

	len = 0;
	tmp = NULL;
	while (str[len] != '\0' && str[len] != '\n') // scorri la stringa fino alla fine o fino alla \n -> e' un ciclo infinito
		{ // si assegna comunque a tmp la duplicazione di str
			len++; // qui len contiene la lunghezza
		}
	if (str[0] == '\0' || !str || !str[len])
	{
		free (str);
		return (NULL);
	}
	if (ft_strchr(str, '\n')) // qiu si dice se lo strchr trova dentro str la \n
	{
		tmp = ft_strdup(ft_strchr(str, '\n') + 1); // qui si assegna a tmp la duplicazione della stringa, dopo \n fino a \0
	}
	else if (!ft_strchr(str, '\n')) // qui si fa il controllo se non c'e' la \n
		tmp = ft_strdup(str);
	free (str); // si libera str -> senno' continuera' a sovrascriversi
	return (tmp); // si ritorna la stringa duplicata
}

char 	*startdivide(char *str) //duplica la stringa dall'inizio fino alla \n
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
	tmp = malloc(len + 2); // quel +2 serve per aggiungere \n e \0
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
	return (tmp); // ritorno tmp che contiene la stringa duplicata
}

char	*ciclo(char *str, int fd)
{
	char		*m;
	int			byte;
	
	byte = 1;
	m = malloc(BUFFER_SIZE + 1); // allochi buffer di lettura +1 che e' lo \0
	if (!m) // controllo che se m non esiste
		return (NULL); // ritorno NULL
	while (byte > 0) // continua a leggere finquando str e' NULL, oppure se str non termina con \n.
	{
		byte = read(fd, m, BUFFER_SIZE); // leggi da file descriptor
		if (byte == -1) // -1 perche' c'e' il rischio che la stringa sia vuota e che gli sia sottratto il -1 per la \n 
		{
			free(m); // si libera m
			free(str); // si libera str
			return (NULL); // si ritorna NULL
		}
		m[byte] = '\0'; // null-termini il buffer appena letto	
		if (!str)
			str = ft_calloc(1, sizeof(char));
		str = ft_strjoin(str, m);
		if(ft_strchr(str, '\n') || byte < BUFFER_SIZE)
			break;
	}
	free(m); // liberi buffer temporaneo
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str; // persistente tra chiamate, accumulatore della riga corrente
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

/* int	main()
{
	//int	fd;
	char	*str;
	
	 fd = open("file.txt", O_RDONLY); */
	/* str = get_next_line(1000);
	printf("%s", str);
	free (str); */
	/* str = get_next_line(fd);
	printf("%s",str);
	free (str);
	str = get_next_line(fd);
	printf("%s", str);
	free (str);
	str = get_next_line(fd);
	printf("%s", str);
	free (str); */
	//return (0);
//} */