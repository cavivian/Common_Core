/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:02:07 by cavivian          #+#    #+#             */
/*   Updated: 2026/02/19 16:22:51 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//heap permette di allocare memoria la cui dimensione e' nota solo durante il runtime della funzione e mantiene i dati anche dopo la fine della funzione che li ha creati

char	*contrnwline(char *buffer, char *str) //buffer -> bytes appena letti da read(sorgente temporanea), *str -> puntatore al puntatore statico che accumula la riga(accumulatore persistente)
{
	int	i; // -> indice per scorerre il buffer
	char *tmp; // -> dovrebbe salvare il vecchio *str
	char *vol; // -> contiene la porzione fino a '\n'

	i = 0; // parti dall'inizio del buffer
	if (!buffer /* || !str */) // se il buffer e' vuoto, esci NOTA: CONTROLLI SOLO BUFFER[0]. NON E' UNA VERIFICA GENERALE
		return (NULL);
	while (buffer && ft_strchr(buffer, '\n')) // scorri il buffer finche' non trovi il fine stringa
	{
			tmp = str;
			vol = ft_strdup(buffer); // parte fino a '\n'
			str = ft_strjoin(tmp, vol); // concatenazione 
			free (tmp);
			free (vol);
			buffer = ft_substr(buffer, i + 1, ft_strlen(buffer) - i - 1); // taglio il buffer lasciando solo il resto dopo '\n'
			return (str);
		
		i++; // incremento del buffer
	}
	return (NULL);
} // in sintesi non: aggiorna *str, riduce buffer, ritorn aqualcosa di coerente, fa free di nulla. e' incompleta

char	*get_next_line(int fd)
{
	static char	*str; // persistente tra chiamate, accumulatore della riga corrente
	char		*m;
	int			byte;

	m = malloc(BUFFER_SIZE + 1); // allochi buffer di lettura
	if (!m)
		return (NULL);
	while (!str || (str && ft_strlen(str) > 0 && str[ft_strlen(str) - 1] != '\n')) // continua a leggere finquando str e' NULL, oppure se str non termina con \n.
	{
		byte = read(fd, m, BUFFER_SIZE); // leggi da file descriptor
		if (byte == 0 || byte == -1)
		{
			free(m);
			free(str);
			return (NULL);
		}
		m[byte] = '\0'; // null-termini il buffer appena letto
		se str vuoto duplica ft_strdup il contenuto di m in str. se str pieno ft_strjoin(str, m).
		if(ft_strchr(str, '\n'))
			break;
	}
	if (byte == 0 && !str) // se EOF e non hai accumulato nulla, ritorna NULL
		return (str);
	free(m); // liberi buffer temporaneo
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