/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:04 by cavivian          #+#    #+#             */
/*   Updated: 2026/08/23 18:38:40 by camilla          ###   ########.fr       */
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
	t_coders *codx = malloc(sizeof(t_coders)); // edo lo aveva scritto con un (coders[1] * sizeof(t_coders))
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
			else if (argv[1][i]) // condizione per controllare i parametri dei millisecondi dei tempi 
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

//qua dentro ci  stanno le chiamate alle funzioni. prima parse
// poi creazione thread, e la creazione dell'array preso dal parse
int	main(int argc, char *argv[])
{
	if (argc != 2)
		return 0;
	t_coders	*coders;

	// assegni variabili
	coders = prova(argc, argv);
	creation_thread(coders);
	return (0);
}
