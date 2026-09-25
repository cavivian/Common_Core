/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread_and_mutex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 15:03:00 by camilla           #+#    #+#             */
/*   Updated: 2026/09/25 13:31:04 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// funzione che mi crea i thread per ogni coder,
// che poi vanno assegnati, ogni coder ha il suo thread
// crea già tutti i thread dell'array.
//(*count)++ -> variabile condivisa con join_threads,
// serve per salvare quanti thread sono stati creati
int	init_coders_threads(t_coders *cod, int size, int *count)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (pthread_create(&cod[i].coder_thread, NULL, coderses, &cod[i]) != 0)
		{
			return (1);
		}
		(*count)++;
		i++;
	}
	return (0);
}
void	init_monitor_threads(t_quantum *q)
{
	if (init_check_monitor(q, q->coders) != 0)
		monitor_errors(q);
}


int	init_mutex(t_coders *cod, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("CODER[%d]: %p\n", i, &cod[i]);
		if (pthread_mutex_init(&cod[i].mutex, NULL) != 0)
		{
			cleanup_all(cod, i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	join_threads(t_coders *cod, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (pthread_join(cod[j].coder_thread, NULL) != 0)
			return (-(j + 1));
		j++;
	}
	return (0);
}
