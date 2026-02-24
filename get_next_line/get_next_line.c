/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:02:07 by cavivian          #+#    #+#             */
/*   Updated: 2026/02/24 10:42:11 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//heap permette di allocare memoria la cui dimensione e' nota solo durante il runtime della funzione e mantiene i dati anche dopo la fine della funzione che li ha creati

/*char	*contrnwline(char *buffer, char *str) //buffer -> bytes appena letti da read(sorgente temporanea), *str -> puntatore al puntatore statico che accumula la riga(accumulatore persistente)
{
	int	i; // -> indice per scorerre il buffer
	char *tmp; // -> dovrebbe salvare il vecchio *str
	char *vol; // -> contiene la porzione fino a '\n'

	i = 0; // parti dall'inizio del buffer
	if (!buffer || !str ) // se il buffer e' vuoto, esci NOTA: CONTROLLI SOLO BUFFER[0]. NON E' UNA VERIFICA GENERALE
	//	return (NULL);
	//while (buffer && ft_strchr(buffer, '\n')) // scorri il buffer finche' non trovi il fine stringa
	//{
			//tmp = str;
		//	vol = ft_strdup(buffer); // parte fino a '\n'
		//	str = ft_strjoin(tmp, vol); // concatenazione 
		//	free (tmp);
		//	free (vol);
		//	buffer = ft_substr(buffer, i + 1, ft_strlen(buffer) - i - 1); // taglio il buffer lasciando solo il resto dopo '\n'
		//	return (str);
		//i++; // incremento del buffer
	//}
	//return (NULL);
//} */// in sintesi non: aggiorna *str, riduce buffer, ritorna qualcosa di coerente, fa free di nulla. e' incompleta 

char	*dividestr1(char *buffer) //char *str) non va bene
{
	int		i;
	int		a;
	char	*tmp;
	char	*vol;

	i = 0;
	while (buffer[i] != '\0')
	{
		a = ft_strlen(buffer);
		while (buffer[i] <= a && buffer[i] == '\n')
		{
			tmp = ft_strdup(buffer);
			return (tmp);
		}
		while (buffer[i] != '\n' || buffer[i] == '\0')
		{
			vol = ft_strdup(buffer);
			return (vol);
		}
		i++;	
	}
	return (NULL);
}

char	*endivide(char *str) // duplica la stringa da dopo la \n fino a \0
{
	int		len;
	char	*tmp;

	len = 0;
	while (str[len] != '\0' || str[len] != '\n') // scorri la stringa fino alla fine o fino alla \n
		len++; // qui len contiene la lunghezza
	if (ft_strchr(str, '\n')) // qiu si dice se lo strchr trova dentro str la \n
		tmp = ft_strdup(ft_strchr(str, '\n') + 1); // qui si assegna a tmp la duplicazione della stringa, dopo \n fino a \0
	else if (!ft_strchr(str, '\n')) // qui si fa il controllo se non c'e' la \n
		tmp = ft_strdup(str); // si assegna comunque a tmp la duplicazione di str
	free (str); // si libera str -> senno' continuera' a sovrascriversi
	return (tmp); // si ritorna la stringa duplicata
}

char 	*startdivide(char *str) //duplica la stringa dall'inizio fino alla \n
{
	int		len;
	char	*tmp;
	
	len = 0;
	while (str[len] != '\0' || str[len] != '\n')
		len++;
	tmp = malloc(len + 2); // quel +2 serve per aggiungere \n e \0
	if (ft_strchr(str, '\n')) // se strchr trova \n
		tmp = ft_strdup(ft_strchr(str, '\n') + 1); // tmp contiene la duplicazione della stringa fino alla \n compresa, infatti +1
	else if (!ft_strchr(str, '\n')) // controllo se non c'e' la \n
		tmp = ft_strdup(str); // tmp contiene la duplicazione della stringa
	free (str); // libero str
	return (tmp); // ritorno tmp che contiene la stringa duplicata
}

char	*get_next_line(int fd)
{
	static char	*str; // persistente tra chiamate, accumulatore della riga corrente
	char		*m;
	int			byte; // indice

	m = malloc(BUFFER_SIZE + 1); // allochi buffer di lettura +1 che e' lo \0
	if (!m) // controllo che se m non esiste
		return (NULL); // ritorno NULL
	while (!str || (str && ft_strlen(str) > 0 && str[ft_strlen(str) - 1] != '\n')) // continua a leggere finquando str e' NULL, oppure se str non termina con \n.
	{
		byte = read(fd, m, BUFFER_SIZE); // leggi da file descriptor
		if (byte == -1) // -1 perche' c'e' il rischio che la stringa sia vuota e che gli sia sottratto il -1 per la \n 
		{
			free(m); // si libera m
			free(str); // si libera str
			return (NULL); // si ritorna NULL
		}
		m[byte] = '\0'; // null-termini il buffer appena letto
		if(!str)
			str = ft_strdup(m); // m perche' contiene la stringa letta
		else
			str = ft_strjoin(str, m);
		free (m);
		if(ft_strchr(str, '\n'))
			break;
	}
	if (byte == 0 && !str) // se EOF e non hai accumulato nulla, ritorna NULL
		return (str);
	free(m); // liberi buffer temporaneo
	/* if (str)
		return (str);
	else
		return (NULL); */
	return (str);
}

int	main()
{
	/* int	fd;

	fd = open("file.txt", O_RDONLY);
	printf("%s", get_next_line(fd)); */
	char	*buffer;

	buffer = "ciao\nciaooooooo\n";
	printf("%s", dividestr(buffer));
	free (buffer);
	return (0);
}