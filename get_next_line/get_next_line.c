/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:02:07 by cavivian          #+#    #+#             */
/*   Updated: 2026/02/19 10:06:24 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//heap permette di allocare memoria la cui dimensione e' nota solo durante il runtime della funzione e mantiene i dati anche dopo la fine della funzione che li ha creati

char	*contrnwline(char *buffer, char **str) //buffer -> bytes appena letti da read(sorgente temporanea), *str -> puntatore al puntatore statico che accumula la riga(accumulatore persistente)
{
	int	i; // -> indice per scorerre il buffer
	char *tmp; // -> dovrebbe salvare il vecchio *str
	char *vol; // -> contiene la porzione fino a '\n'

	i = 0; // parti dall'inizio del buffer
	if (!buffer) // se il buffer e' vuoto, esci NOTA: CONTROLLI SOLO BUFFER[0]. NON E' UNA VERIFICA GENERALE
		return (NULL);
	while (buffer[i] != '\0') // scorri il buffer finche' non trovi il fine stringa
	{
		if (buffer[i] == '\n') // se trovi la newline fai:
		{
			tmp = *str; // salvi il vecchio accumulo
			vol = ft_substr(buffer, 0, i + 1); // allochi nuova memoria da buffer[0 - '\n'], allocazione heap nuova. ALLOCATA MA NON USATA
			buffer = ft_strjoin(buffer, tmp); // errori: faccio buffer + tmp, invece di *str + vol
			// mancano i free
		}
		i++; // incremento del buffer
	}
} // in sintesi non: aggiorna *str, riduce buffer, ritorn aqualcosa di coerente, fa free di nulla. e' incompleta

char	*get_next_line(int fd)
{
	static char	*str; // persistente tra chiamate, accumulatore della riga corrente
	char		*m; // buffer temporaneo per read
	int			i;

	m = malloc(BUFFER_SIZE + 1); // allochi buffer di lettura
	if (!m)
		return (NULL);
	while (!str || (str && ft_strlen(str) > 0 && str[ft_strlen(str) - 1] != '\n')) // continua a leggere finquando str e' NULL, oppure se str non termina con \n.
	{
		i = read(fd, m, BUFFER_SIZE); // leggi da file descriptor
		if (i == 0 || i == -1)
			break;
		m[i] = '\0'; // null-termini il buffer appena letto
		contrnwline(m, &str); // passi il buffer appena letto
	}
	if (i == 0 && !str) // se EOF e non hai accumulato nulla, ritorna NULL
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