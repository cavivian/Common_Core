/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 11:18:30 by camilla           #+#    #+#             */
/*   Updated: 2026/09/25 13:40:09 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// corrisponde a pick_metric
t_wait_node	create_wait_node(t_coders *coder, t_algorithm algo)
{
	t_wait_node	node;
	struct timeval	tv;
	long	actually_time;

	gettimeofday(&tv, NULL);
	actually_time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
//	printf("%d entrato dentro create_wait_node", coder->index);
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

int	heap_father(int i)
{
	return ((i - 1) / 2);
}

int	heap_left_son(int i)
{
	return (2 * i + 1);
}

int	heap_right_son(int i)
{
	return (2 * i + 2);
}
