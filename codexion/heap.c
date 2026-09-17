/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:01:38 by cavivian          #+#    #+#             */
/*   Updated: 2026/09/17 16:24:26 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

t_heap	*create_heap(int size)
{
	t_heap	*heap;

	heap = malloc(sizeof(t_heap));
	if (!heap)
		return (NULL);
	heap->array = malloc(sizeof(t_wait_node) * size);
	if (!heap->array)
	{
		free(heap);
		return (NULL);
	}
	heap->index = 0;
	has_priority(heap->array[0].coder, heap->array[1].coder);
	swap(heap->array[0], heap->array[1]);
	return (heap);
}
