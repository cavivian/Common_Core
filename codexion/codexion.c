/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:04 by cavivian          #+#    #+#             */
/*   Updated: 2026/08/24 12:05:23 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"


// funzione "main"  che conterra' tutto il loop delle azioni dei vari coders
void *coderses(void *arg)
{
	(void)arg;
	printf("thread creato!");
	return NULL;
}

int creation_thread(t_coders *coders)
{
	t_coders *codx = malloc(sizeof(t_coders)); // Edo lo aveva scritto con un (coders[1] * sizeof(t_coders))
	int i;

	i = 0;
	while (i < coders[1].index)
	{
		if (pthread_create(&coders, NULL, &coderses, NULL) != 0)
		{
			printf("uncreated Thread");
			return 1;
		}
		i++;
	}
	while(i < coders[i].index)
	{
		if (pthread_join(codx, NULL) != 0)
			return 2;
		i++;
	}
	free(codx);
	return 0;
}

int parse(int argc, char *argv[])
{
	int	args; // variabile che scorre i vari argomenti di argc
	int	i; // indice che scorre i vari int che compongono gli argomenti
	
	i = 0;
	args = 0;
	while(args < argc) // si scorre args finchè è minore di argc
	{
		while(argv[args][i]) 
		{
			if (!(atoi(argv[args][i]) >= 0 && atoi(argv[args][i]) <= 9))
				return 0;
			else if (argv[args][i]) // condizione per controllare i parametri dei millisecondi dei tempi 
			i++;
		}
		args++;
	}
	return 1;
}

// c'e'da fare una funzione che faccia il parse e i controlli di argv
int *prova(int argc, char *argv[])
{
	int i;
	int j;
	int *arr;

	arr = malloc(sizeof(int) * atoi(argv[1]));
	i = 1;
	while (i < argc)
	{
		j = 0;
		while(argv[i][j] != '\0')
		{
			if (((argv[i][j] >= 'a' && argv[i][j] <= 'z') &&
			(argv[i][j] >= 'A' && argv[i][j] <= 'Z')))
			{
				printf("This argument must be a number. Retry...");
				return 0;
			}
			j++;
		}
		arr[i - 1] = atoi(argv[i]);
		i++;
	}
	free(arr);
	return (arr);
}


// qui dentro ci dovrebbe essere la creazione della struct con i thread dei vari elementi
// che servono al coder per esistere
// la funzione che viene passata ai create è il "main" del progetto
t_coders *init_array(int size) 
{
	t_coders *cod = malloc(sizeof(t_coders) * size);
	int i;

	i = 0;
	while(i < size)
	{
		if (pthread_create(cod[i].coder_thread, NULL, &coderses, NULL) != 0)
			return NULL;
		else if (pthread_mutex_create(cod[i].time_to_compile, NULL, &coderses, NULL) != 0)
			return NULL;
		else if (pthread_mutex_create(cod[i].time_to_refactor, NULL, &coderses, NULL) != 0)
			return NULL;
		else if (pthread_mutex_create(cod[i].time_to_debug, NULL, &coderses, NULL) != 0)
			return NULL;
		i++;
	}
	if (pthread_join(cod, NULL) != 0)
		return NULL;
	return (cod);
}


//qua dentro ci  stanno le chiamate alle funzioni. prima parse
// poi creazione thread, e la creazione dell'array preso dal parse
int	main(int argc, char *argv[])
{
	if (argc != 9)
		return 0;
	parse(argc, argv);
	// qui va passato il parse, se va a buon fine prosegue, altrimenti si ferma il programma
	t_coders	*coders; // array di struct che contiene i thread che compongono le struct con i vari  dati dei vari coders

	// assegni variabili
	// argv[1] rappresenta il numero delle struct dentro l'array che devono essere create
	coders = init_array(atoi(argv[1])); // in questa funzione quindi vanno creati i thread veri e propri,
	// sia per i coders, sia per i vari parametri che devono avere
	// ! alcuni thread sono di tipo mutex (specificato dal subject)
	//creation_thread(coders);
	return (0);
}
