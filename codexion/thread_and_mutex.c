/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_and_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 15:03:00 by camilla           #+#    #+#             */
/*   Updated: 2026/08/28 17:36:07 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// funzione che mi crea i thread per ogni coder, che poi vanno assegnati, ogni coder ha il suo
// crea già tutti i thread dell'array.
int	init_threads(t_coders *cod, int size, int *count) // finita
{
	int	i;

	i = 0;
	while(i < size)
	{
		if (pthread_create(&cod[i].coder_thread, NULL, coderses, &cod[i]) != 0)
		{
			return (0);
		}
		(*count)++;
		i++;
	}
	return (1);
}


int	init_mutex(t_coders *cod, int size) // finita
{
	int i;

	i = 0;
	while(i < size)
	{
		if (pthread_mutex_init(&cod[i].mutex, NULL) != 0)
		{
			cleanup_coders(cod, i);
			return (0);
		}
		i++;
	}
	return (1);
}

// funzion eche crea gli array per le dongle dei coders
t_dongle	*init_array_dongle(t_quantum *q) // finita
{
	int	number;
	t_dongle *dongle;
	int	i;

	number = q->config.n_of_coders;
	i = 0;
	dongle = malloc(sizeof(t_dongle) * number);
	if (!dongle)
		return (NULL);
	memset(dongle, 0, number * sizeof(t_dongle));
	while(i < number)
	{
		if (pthread_mutex_init(&dongle[i].m_dongle, NULL) != 0)
		{
			cleanup(dongle, i);
			return NULL;
		}
		i++;
	}
	return (dongle);
}

// funzione che crea l'array di coders, e assegna a ogni cella il proprio valore
// gli errori si gestiscono nel main
t_coders *init_array_coders(t_quantum *q) // finita , va solo spezzata perchè troppo lunga
{
	int			i;
	t_coders	*coders;
	int			num;
	int			count;

	count = 0;
	num = q->config.n_of_coders; // numero dei coder
	coders = malloc(sizeof(t_coders) * num); // malloc dell'array
	if (!coders)
		return (NULL);
	memset(coders, 0, num * sizeof(t_coders));
	i = 0;
	while (i < num)
	{
		coders[i].index = i;
		coders[i].quantum = q;
		i++;
	}	
	if (init_mutex(coders, num) != 1)
		return (NULL);
	if (init_threads(coders, num, &count) != 1)
	{
		if (join_threads(coders, count) != 1)
			return (NULL);
		cleanup_coders(coders, num);
			return (NULL);
	}	
	return (coders);
}
