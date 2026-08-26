/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:04 by cavivian          #+#    #+#             */
/*   Updated: 2026/08/26 17:05:21 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// --------------------

// array dongle, va allocato e inizializzazione dei mutex e memset -> FATTO!
// array coders , allocati n coders e inizializzati i mutex e memset(dopo allocazione)
// creazione pthread_mutex
// in quantum -> mutex stampa
// tutti i mutex della dongle

// --------------------


// manca un free da qualche parte

// funzione "main" che conterra' tutto il loop delle azioni dei vari coders
void *coderses(void *arg)
{
	//t_coders *coders = (t_coders *)arg;
	arg = (void *)arg;
	printf("\nthread creato!\n");
	return NULL;
}

// funzione pressochè inutile, perchè è già stata fatta
// int creation_thread(t_coders *coders)
// {
	// 	t_coders *codx = malloc(sizeof(t_coders)); // Edo lo aveva scritto con un (coders[1] * sizeof(t_coders))
	// 	int i;

	// 	i = 0;
	// 	while (i < coders[1].index)
	// 	{
// 		if (pthread_create(&coders, NULL, coderses, NULL) != 0)
// 		{
// 			printf("uncreated Thread");
// 			return 1;
// 		}
// 		i++;
// 	}
// 	while(i < coders[i].index)
// 	{
// 		if (pthread_join(codx, NULL) != 0)
// 			return 2;
// 		i++;
// 	}
// 	free(codx);
// 	return 0;
//  }


// parte del parse per controllare che i primi 7 arg siano int
// e che l'ultimo sia una stringa, controllo con strcmp
int validation(int argc, char **argv)
{
	int args;
	int	i;

	args = 1;
	i = 0;
	while(args < argc - 1) // si scorre args finchè è minore di argc
	{
		i = 0;
		while(argv[args][i]) 
		{
			if (!(argv[args][i] >= 48 && argv[args][i] <= 57))
				return (1);
			i++;
		}
		args++;
	}
	if (strcmp(argv[7], "FIFO") && strcmp(argv[7], "fifo")
		&& strcmp(argv[7], "EDF") && strcmp(argv[7], "edf"))
			return (0);
	return (0);
}

// parse che chiama validation
int parse(t_quantum *q, int argc, char **argv)
{
	if (!validation(argc, argv))
		return (0);
	if (!strcmp(argv[7], "FIFO") || !strcmp(argv[7], "fifo"))
		q->config.algorithm = FIFO;
	else if (!strcmp(argv[7], "edf") || !strcmp(argv[7], "EDF"))
		q->config.algorithm = EDF;
	q->config.n_of_coders = atoi(argv[1]);
	q->config.burnout = atoi(argv[2]);
	q->config.compile = atoi(argv[3]);
	q->config.debug = atoi(argv[4]);
	q->config.refactor = atoi(argv[5]);
	q->config.number_of_compiles_required = atoi(argv[6]);
	q->config.dongle_cooldown = atoi(argv[7]);
	return (1);	
}

void	cleanup(t_dongle *dongle, int i) // funzione che gestisce gli errori di creazione dei mutex
{
	// Distrugge i 3 mutex dei coder precedenti, già completamente inizializzati
	int j;
	
	j = 0;
	while (j < i)
	// I coder con indice < i sono già completamente inizializzati
	{
		pthread_mutex_destroy(&dongle[j]);
		j++;
	}
	free(dongle);
}


void	cleanup_all(t_coders *cod, int size) // funzione che distrugge i mutex creati se si ha problemi con il join dei thread
{
	int i;
	
	i = 0;
	while (i < size)
	{
		i++;
	}
	free(cod);
}



int join_threads(t_coders *cod, int i)
{
	int j;

	j = 0;
	while(j < i)
	{
		if (pthread_join(cod[j].coder_thread, NULL) != 0)
		{
			cleanup_all(cod, i);
			return (1);
		}
		j++;
	}
	return (0);
}

// qui dentro ci dovrebbe essere la creazione della struct con i thread dei vari elementi (troppo lunga)
// che servono al coder per esistere
// la funzione che viene passata ai create è il "main" del progetto
// size è la conversione in int del num passato da argc che rappresenta il numero dei coders

t_coders *init_array(t_quantum *quantum, int size) 
{
	t_coders *cod = malloc(sizeof(t_coders) * size); // si alloca una struct per quanti sono i coders
	if (!cod)
		return NULL;
	int i;
	int status; // variabile che mi serve per capire quanti mutex di cod[i] sono stati inizializzati con successo
	
	i = 0;
	while(i < size)
	{
		status = 0; // mi serve per la funzione cleanup()
		cod[i].index = i;
		
		status++;
		if (pthread_create(&cod[i].coder_thread, NULL, coderses, &cod[i]) != 0)
		{
			cleanup(cod, i);
			return NULL;
		}
		i++;
	}
	if (join_threads(cod, i) != 0)
		return NULL;
	return (cod);
}


//qua dentro ci  stanno le chiamate alle funzioni. prima parse
// poi creazione thread, e la creazione dell'array preso dal parse
// se il parse fallisce il programma deve terminare
int	main(int argc, char *argv[])
{
	t_quantum q;
	
	if (argc != 2)
		return 0;
		// qui va passato il parse, se va a buon fine prosegue, altrimenti si ferma il programma
	t_coders	*coders; // array di struct che contiene i thread che compongono le struct con i vari  dati dei vari coders
	if (parse(&q, argc, argv) != 0)
	{
			// assegni variabili
			// argv[1] rappresenta il numero delle struct dentro l'array che devono essere create
		coders = init_array(&q); // in questa funzione quindi vanno creati i thread veri e propri,
			// sia per i coders, sia per i vari parametri che devono avere
			// ! alcuni thread sono di tipo mutex (specificato dal subject)
			//creation_thread(coders); // questa funzione ormai non serve più perchè l'ho fatto dentro init array
	}
	printf("%ld", coders->coder_thread);	
	return 0;
}
