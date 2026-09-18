/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 11:18:30 by camilla           #+#    #+#             */
/*   Updated: 2026/09/18 16:53:56 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

t_wait_node	create_wait_node(t_heap *heap, t_coders *coder, t_algorithm algo)
{
	t_wait_node node;

	node.coder = coder;
	if (algo == FIFO)
		node.value = heap->current_size;
	else if (algo == EDF)
		node.value = coder->last_compile_start;
	return (node);
}

int heap_father(int i)
{
    return (i - 1) / 2;
}
int heap_left_son(int i)
{
    return (2 * i + 1);
}
int heap_right_son(int i)
{
    return (2 * i + 2);
}