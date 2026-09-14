/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread_and_mutex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 15:03:00 by camilla           #+#    #+#             */
/*   Updated: 2026/09/14 09:46:18 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// funzione che mi crea i thread per ogni coder, che poi vanno assegnati, ogni coder ha il suo thread
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
		(*count)++;  // variabile condivisa con join_threads, serve per salvare quanti thread sono stati creati 
		i++;
	}
	return (1);
}


int	init_mutex(t_coders *cod, int size) // finita
{
	int	i;

	i = 0;
	while(i < size)
	{
		if (pthread_mutex_init(&cod[i].mutex, NULL) != 0)  // mutex specifico per la struct t_coders
		{
			cleanup_all(cod, i);
			return (0);
		}
		i++;
	}
	return (1);
}

// funzione che crea gli array per le dongle dei coders
t_dongle	*init_array_dongle(t_quantum *q) // finita
{
	int			number;
	t_dongle	*dongle;
	int			i;

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
			cleanup(dongle, number);
			return NULL;
		}
		i++;
	}
	return (dongle);
}

// funzione che crea l'array di coders, e assegna a ogni cella il proprio valore
// gli errori si gestiscono nel main
t_coders	*init_array_coders(t_quantum *q, int *count, t_dongle *dongle) // finita , va solo spezzata perchè troppo lunga
{
	int			i; // indice per scorrere l'array dei threads dei coders
	t_coders	*coders; 
	int			num; // numero totale dei coders

	num = q->config.n_of_coders; // numero dei coder
	coders = malloc(sizeof(t_coders) * num); // malloc dell'array
	if (!coders)
		return (NULL);
	memset(coders, 0, num * sizeof(t_coders)); // inizializza tutti i byte di allocazione a 0
	i = 0;
	while (i < num) // scorre i coder fino all'ultimo, e assegna a ognuno i suoi valori
	{
		coders[i].quantum = q; // la struct che contiene tutti i valori dei coder
		coders[i].last_compile_start = q->simulation_start; // ogni volta si riaggiorna, sono gli ms trascorsi dall'ultima compilazione 
		coders[i].n_of_compiles = 0; // incrementa ogni volta 
		coders[i].index = i + 1; // indice di ciascun coder, devono partire da 1
		i++; // indice della struct dei coders, ogni i rappresenta un coder
	}	
	if (init_mutex(coders, num) != 1) // si inizializzano i mutex per i vari coder
		return (NULL);
	give_dongle(coders, dongle, num);
	if (init_threads(coders, num, count) != 1) // si inizializzano i thread
	{
		if (join_threads(coders, *count) != 1) // si joinano i thread
			return (NULL);
		cleanup_all(coders, num);
		return (NULL);
	}	
	return (coders);
}


int	join_threads(t_coders *cod, int i) // finita
{
	int	j;

	j = 0;
	while(j < i) // i sono i thread effettivamente creati
	{
		if (pthread_join(cod[j].coder_thread, NULL) != 0)
			return (-(j + 1));
		j++;
	}
	return (1);
}
