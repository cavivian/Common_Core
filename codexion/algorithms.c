/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 11:18:30 by camilla           #+#    #+#             */
/*   Updated: 2026/09/29 13:42:07 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// crea il nodo con il valore da passare all'heap per formare la queue
t_wait_node	create_wait_node(t_coder *coder, t_algorithm algo)
{
	t_wait_node	node;
	long		actually_time;

	actually_time = get_time();
	node.coder = coder;
	if (algo == FIFO)
		node.value = actually_time;
	else if (algo == EDF)
	{
		pthread_mutex_lock(&coder->mutex);
		node.value = coder->last_compile_start;
		pthread_mutex_unlock(&coder->mutex);
	}
	return (node);
}

// espressione per sapere in quale posizione si trova il padre nell'heap
int	heap_father(int i)
{
	return ((i - 1) / 2);
}

// funzione per sapere dove si trova il figlio sinisto dentro heap
int	heap_left_son(int i)
{
	return (2 * i + 1);
}

// espressione per sapere dove si trova il figlio destro
int	heap_right_son(int i)
{
	return (2 * i + 2);
}
