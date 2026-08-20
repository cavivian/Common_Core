/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:04 by cavivian          #+#    #+#             */
/*   Updated: 2026/08/20 17:54:54 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"


// funzione "main" che conterra' tutto il loop delle azioni dei vari coders
void *coderses(void *arg)
{
	(void)arg;
	printf("thread creato!");
	return NULL;
}

int creation_thread(pthread_t *coders)
{
	t_coders *codx = malloc(coders[1] * sizeof(t_coders));
	int i;

	i = 0;
	while (i < (int)coders[1])
	{
		if (pthread_create(&coders[1], NULL, &coderses, NULL) != 0)
		{
			printf("uncreated Thread");
			return 1;
		}
		if (pthread_join(coders[1], NULL) != 0)
			return 2;
		i++;
	}
	free(codx);
	return 0;
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

// c'e'da fare una funzione che faccia il parse e i controlli di argv
t_coders *init_array()
{
	int i;
	int j;
	int k;
	t_coders *arr;

	arr = malloc(sizeof(t_coders) * atoi(argv[1]));
	i = 1;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while(argv[i][j] != '\0')
		{
			if (((argv[i][j] >= 'a' && argv[i][j] <= 'z') &&
			(argv[i][j] >= 'A' && argv[i][j] <= 'Z')))
				return NULL;
			j++;
		}
		arr[k] = atoi(argv[i]);
		k++;
		i++;
	}
	free(arr);
	return (*arr);
}

//qua dentro ci  stanno le chiamate alle funzioni. prima parse
// poi creazione thread, e la creazione dell'array preso dal parse
int	main(int argc, char *argv[])
{
	if (argc != 2)
		return 0;
	pthread_t	*coders;

	coders = NULL;
	// assegni variabili
	coders = parse(argc, argv);
	creation_thread(coders);
	return (0);
}
