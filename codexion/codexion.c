/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:04 by cavivian          #+#    #+#             */
/*   Updated: 2026/08/19 18:24:26 by camilla          ###   ########.fr       */
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

int creation_thread(pthread_t coders[])
{
	t_coders *codx = malloc(coders[1] * sizeof(t_coders));
	int i;

	i = 0;
	while (i < coders[1])
	{
		if (pthread_create(&coders, NULL, &coderses, NULL) != 0)
		{
			printf("uncreated Thread");
			return 1;
		}
		if (pthread_join(codx, NULL) != 0)
			return 2;
		i++;
	}
	free(codx);
	return 0;
}

// c'e'da fare una funzione che faccia il parse e i controlli di argv
int *parse(int argc, char *argv[])
{
	int i;
	int j;
	int *arr;

	arr = malloc(sizeof(int) * argc);
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
	pthread_t	*coders;

	// assegni variabili
	*coders = parse(argc, argv);
	creation_thread(coders);
	return (0);
}
