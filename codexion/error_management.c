/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 10:18:46 by camilla           #+#    #+#             */
/*   Updated: 2026/09/28 14:36:13 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	cleanup_dongle(t_dongle *dongle, int i)
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

void	cleanup_all(t_coder *cod, int size)
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

void	free_heap(t_heap *heap)
{
	free(heap->array);
	free(heap);
}

// void	mutex_unlock_and_broadcast(t_coders *cod)
// {
// 	pthread_mutex_unlock(&cod->dongle_dx->m_dongle);
// 	pthread_mutex_unlock(&cod->dongle_sx->m_dongle);
// 	pthread_cond_broadcast(&cod->quantum->service_condition);
// }
