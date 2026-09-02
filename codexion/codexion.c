/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:04 by cavivian          #+#    #+#             */
/*   Updated: 2026/09/02 09:24:13 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"


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
int validation(int argc, char **argv) // finita
{
	int args;
	int	i;

	args = 1;
	i = 0;
	while(args < argc - 1) // si scorre args finchè è minore di argc
	{
		i = 0;
		if (argv[args][i] == '\0') // controlla che non venga passata una stringa vuota
			return (0);
		while(argv[args][i]) 
		{
			if (!(argv[args][i] >= '0' && argv[args][i] <= '9'))
				return (0);
			i++;
		}
		args++;
	}
	if (strcmp(argv[8], "edf") != 0 && strcmp(argv[8], "fifo") != 0)
			return (0);
	return (1);
}

// parse che chiama validation
// controlla che tutti i parametri passati siano int
// e li assegna a ogni variabile della struct quantum 
int parse(t_quantum *q, int argc, char **argv) // finita
{
	if (!validation(argc, argv))
		return (0);
	if (!strcmp(argv[8], "fifo"))
		q->config.algorithm = FIFO;
	else if (!strcmp(argv[8], "edf"))
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

int join_threads(t_coders *cod, int i) // finita
{
	int j;

	j = 0;
	while(j < i)
	{
		if (pthread_join(cod[j].coder_thread, NULL) != 0)
			return (-(j + 1));
		j++;
	}
	return (1);
}

void	cleanup_all(t_coders *cod, int size, int result) // funzione che distrugge i mutex creati se si ha problemi con il join dei thread
{
	int i;
	
	i = 0;
	if (result == 1) // vuoldire che il join è andato bene
		result = size;
	while (i < result)
	{
		pthread_mutex_destroy(&cod[i].mutex);
		i++;
	}
	free(cod);
}


//qua dentro ci  stanno le chiamate alle funzioni. prima parse
// poi creazione thread, e la creazione dell'array preso dal parse
// se il parse fallisce il programma deve terminare
int	main(int argc, char *argv[])
{
	t_quantum		q;
	int				result; // risultato del tentativo di tutti i join
	struct timeval	tv;
	t_check			check;
	
	if (argc != 9)
		return 0;
	if (validation(argc, argv) == 1)
	{
		t_coders	*coders; // array di struct che contiene i thread che compongono le struct con i vari  dati dei vari coders
		if (parse(&q, argc, argv) == 1)
		{
			// assegni variabili
			// argv[1] rappresenta il numero delle struct dentro l'array che devono essere create
			q.simulation_stop = 0;
			gettimeofday(&tv, NULL);
			q.simulation_start = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
			pthread_mutex_init(&q.m_simulation_stop, NULL);
			coders = init_array_coders(&q); // in questa funzione quindi vanno creati i thread veri e propri,
			if (coders == NULL)
				return (0);
			init_check_monitor(&check, &q, coders);
			cleanup_all(coders, q.config.n_of_coders, result);
			return (0);
		}
		return (0);
	}	// qui va passato il parse, se va a buon fine prosegue, altrimenti si ferma il programma
	return 0;
}

// sia per i coders, sia per i vari parametri che devono avere
				// ! alcuni thread sono di tipo mutex (specificato dal subject)
				//creation_thread(coders); // questa funzione ormai non serve più perchè l'ho fatto dentro init array

// void	cleanup(t_coders *cod, int i, int status) // funzione che gestisce gli errori di creazione dei mutex
// {
// 	// Distrugge i 3 mutex dei coder precedenti, già completamente inizializzati
// 	int j;
	
// 	j = 0;
// 	while (j < i)
// 	// I coder con indice < i sono già completamente inizializzati
// 	{
// 		pthread_mutex_destroy(cod[j].quantum->config.compile);
// 		pthread_mutex_destroy(cod[j].quantum->config.refactor);
// 		pthread_mutex_destroy(cod[j].quantum->config.debug);
// 		j++;
// 	}
// 	if (status == 1)
// 		pthread_mutex_destroy(cod[i].quantum->config.compile);
// 	else  if (status == 2)
// 	{
// 		pthread_mutex_destroy(cod[i].quantum->config.compile);
// 		pthread_mutex_destroy(cod[i].quantum->config.refactor);
// 	}
// 	else if(status == 3)
// 	{
// 		pthread_mutex_destroy(cod[i].quantum->config.compile);
// 		pthread_mutex_destroy(cod[i].quantum->config.refactor);
// 		pthread_mutex_destroy(cod[i].quantum->config.debug);
// 	}
// 	free(cod);
// }