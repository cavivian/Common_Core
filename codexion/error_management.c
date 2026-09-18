/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 10:18:46 by camilla           #+#    #+#             */
/*   Updated: 2026/09/18 13:21:26 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	cleanup(t_dongle *dongle, int i) // funzione che gestisce gli errori di creazione dei mutex della dongle
{
	int	j;
	
	j = 0;
	while (j < i)
	{
		pthread_mutex_destroy(&dongle[j].m_dongle);
		j++;
	}
	free(dongle);
}


void	cleanup_all(t_coders *cod, int size) // funzione che distrugge i mutex creati se si ha problemi con il join dei thread
{
	int	i;
	
	i = 0;
	while (i < size)
	{
		pthread_mutex_destroy(&cod[i].mutex);
		i++;
	}
	free(cod);
}

// controlla se la simulazione è finita o no.
int	check_simulation(t_coders *coders)
{
	pthread_mutex_lock(&coders->quantum->m_simulation_stop);
	if (coders->quantum->simulation_stop == 1)
	{
		pthread_mutex_unlock(&coders->quantum->m_simulation_stop);
		return (1);
	}
	pthread_mutex_unlock(&coders->quantum->m_simulation_stop);
	return (0);
}

void	free_heap(t_heap *heap)
{
	free(heap->array);
	free(heap);
}
