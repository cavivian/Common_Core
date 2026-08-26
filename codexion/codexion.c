/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:04 by cavivian          #+#    #+#             */
/*   Updated: 2026/08/26 11:08:04 by camilla          ###   ########.fr       */
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

// c'è da fare una funzione che faccia il parse e i controlli di argv
// c'è ancora da fare tutti i controlli per i mutex e i parametri passati come millisecondi
int parse(int argc, char **argv)
{
	int	args; // variabile che scorre i vari argomenti di argc
	int	i; // indice che scorre i vari int che compongono gli argomenti
	
	i = 0;
	args = 1;
	while(args < argc) // si scorre args finchè è minore di argc
	{
		while(argv[args][i]) 
		{
			if (!(atoi(argv[i]) >= 0 && atoi(argv[i]) <= 9))
			return (0);
			//else if (argv[args][i]) // condizione per controllare i parametri dei millisecondi dei tempi 
			i++;
		}
		args++;
	}
	return (1);
}

void	cleanup(t_coders *cod, int i, int status) // funzione che gestisce gli errori di creazione dei mutex
{
	// Distrugge i 3 mutex dei coder precedenti, già completamente inizializzati
	int j;
	
	j = 0;
	while (j < i)
	// I coder con indice < i sono già completamente inizializzati
	{
		pthread_mutex_destroy(&cod[j].time_to_compile);
		pthread_mutex_destroy(&cod[j].time_to_refactor);
		pthread_mutex_destroy(&cod[j].time_to_debug);
		j++;
	}
	if (status == 1)
		pthread_mutex_destroy(&cod[i].time_to_compile);
	else  if (status == 2)
	{
		pthread_mutex_destroy(&cod[i].time_to_compile);
		pthread_mutex_destroy(&cod[i].time_to_refactor);
	}
	else if(status == 3)
	{
		pthread_mutex_destroy(&cod[i].time_to_compile);
		pthread_mutex_destroy(&cod[i].time_to_refactor);
		pthread_mutex_destroy(&cod[i].time_to_debug);
	}
	free(cod);
}


void	cleanup_all(t_coders *cod, int size) // funzione che distrugge i mutex creati se si ha problemi con il join dei thread
{
	int i;
	
	i = 0;
	while (i < size)
	{
		pthread_mutex_destroy(&cod[i].time_to_compile);
		pthread_mutex_destroy(&cod[i].time_to_refactor);
		pthread_mutex_destroy(&cod[i].time_to_debug);
		i++;
	}
	free(cod);
}

int parse(int argc, char *argv[])
{
	int args;
	int i;
	
	i = 0;
	args = 0;
	while(args < argc)
	{
		
		args++;
	}
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
t_coders *init_array(int size) 
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
		if (pthread_mutex_init(&cod[i].time_to_compile, NULL) != 0)
		{
			cleanup(cod, i, status); // funzione che distrugge i mutex in base allo status
			return NULL;
		}
		status++;
		if (pthread_mutex_init(&cod[i].time_to_refactor, NULL) != 0)
		{
			cleanup(cod, i, status);
			return NULL;
		}
		status++;
		if (pthread_mutex_init(&cod[i].time_to_debug, NULL) != 0)
		{
			cleanup(cod, i, status);
			return NULL;
		}
		status++;
		if (pthread_create(&cod[i].coder_thread, NULL, coderses, &cod[i]) != 0)
		{
			cleanup(cod, i, status);
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
	if (argc != 2)
		return 0;
		// qui va passato il parse, se va a buon fine prosegue, altrimenti si ferma il programma
	t_coders	*coders; // array di struct che contiene i thread che compongono le struct con i vari  dati dei vari coders
	if (parse(argc, argv) != 0)
	{
		int conv = atoi(argv[1]);
			// assegni variabili
			// argv[1] rappresenta il numero delle struct dentro l'array che devono essere create
		coders = init_array(conv); // in questa funzione quindi vanno creati i thread veri e propri,
			// sia per i coders, sia per i vari parametri che devono avere
			// ! alcuni thread sono di tipo mutex (specificato dal subject)
			//creation_thread(coders); // questa funzione ormai non serve più perchè l'ho fatto dentro init array
	}
	printf("%ld", coders->coder_thread);	
	return 0;
}
