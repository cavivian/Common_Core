/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_mutex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 15:03:00 by camilla           #+#    #+#             */
/*   Updated: 2026/08/27 17:55:04 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// funzione che mi crea i thread per ogni coder, che poi vanno assegnati, ogni coder ha il suo
// crea già tutti i thread dell'array.
int	init_threads(t_coders *cod, int size)
{
	int	i;

	i = 0;
	while(i < size)
	{
		if (pthread_create(&cod[i].coder_thread, NULL, coderses, NULL) != 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

// funzion eche crea gli array per le dongle dei coders
t_dongle	*init_array_dongle(t_quantum *q)
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
t_coders *init_array_coders(t_quantum *q)
{
	int i;
	t_coders *coders;
	int num;

	num = q->config.n_of_coders;
	coders = malloc(sizeof(t_coders) * num);
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
	coders[i].coder_thread = init_threads(coders, num);
	coders[i].mutex = i;
	return (coders);
}
