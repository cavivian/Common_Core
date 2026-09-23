/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 11:18:30 by camilla           #+#    #+#             */
/*   Updated: 2026/09/23 15:31:19 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// corrisponde a pick_metric
t_wait_node	create_wait_node(t_coders *coder, t_algorithm algo, long actually_time)
{
	t_wait_node	node;

	printf("%d entrato dentro create_wait_node", coder->index);
	node.coder = coder;
	if (algo == FIFO)
		node.value = actually_time;
	else if (algo == EDF)
		node.value = coder->last_compile_start;
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
