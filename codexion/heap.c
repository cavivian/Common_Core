/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:01:38 by cavivian          #+#    #+#             */
/*   Updated: 2026/09/28 11:08:05 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// serve per swappare gli elementi della queue
void	ft_swap(t_wait_node *a, t_wait_node *b)
{
	t_wait_node	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// confronto il nodo passato per parametro
// con il padre e lo faccio salire, dopo averlo inserito nell'heap 
t_heap	*push_into_the_heap(t_heap *heap, t_wait_node node)
{
	int	i;

	if (heap->size <= heap->current_size)
		return (NULL);
	heap->current_size++;
	i = heap->current_size - 1;
	heap->array[i] = node;
	while (i != 0 && heap->array[heap_father(i)].value > heap->array[i].value)
	{
		ft_swap(&heap->array[heap_father(i)], &heap->array[i]);
		i = heap_father(i);
	}
	
	return (heap);
}

// controllo di chi ha la priorita'
void	check_priority_queue(t_heap *heap, int index)
{
	int	left_son;
	int	right_son;
	int	best;

	while (index < heap->current_size)
	{
		left_son = heap_left_son(index);
		right_son = heap_right_son(index);
		best = index;
		if (left_son < heap->current_size
			&& heap->array[left_son].value > heap->array[best].value)
			best = left_son;
		if (right_son < heap->current_size
			&& heap->array[right_son].value > heap->array[best].value)
			best = right_son;
		if (best == index)
			break ;
		else
			ft_swap(&heap->array[index], &heap->array[best]);
		index = best;
	}
}

// quando trova il nodo maggiore lo toglie dalla coda
int	delete_max_priority_node(t_heap *heap)
{
	if (heap == NULL || heap->current_size <= 0)
		return (1);
	if (heap->current_size == 1)
	{
		heap->current_size--;
		return (0);
	}
	heap->array[0] = heap->array[heap->current_size - 1];
	heap->current_size--;
	check_priority_queue(heap, 0);
	return (0);
}

// funzione che crea il nodo e lo passa a heap
void	register_heap(t_coders *coder)
{
	t_wait_node	node;

	node = create_wait_node(coder, coder->quantum->config.algorithm);
	pthread_mutex_lock(&coder->dongle_sx->m_dongle);
	push_into_the_heap(&coder->dongle_sx->heap, node);
	pthread_mutex_unlock(&coder->dongle_sx->m_dongle);
	//printf("\n%d [lct: %ld] entrato in push_into_the_heap. current nodes: (DONGLE_SX) [0]: %p (value: %ld), [1]: %p (value: %ld)\n", coder->index, coder->last_compile_start,
		//coder->dongle_sx->heap.array[0].coder, coder->dongle_sx->heap.array[0].value, coder->dongle_sx->heap.array[1].coder, coder->dongle_sx->heap.array[1].value);
	pthread_mutex_lock(&coder->dongle_dx->m_dongle);
	push_into_the_heap(&coder->dongle_dx->heap, node);
	pthread_mutex_unlock(&coder->dongle_dx->m_dongle);
	//printf("\n%d [lct: %ld] entrato in push_into_the_heap. current nodes: (DONGLE_DX) [0]: %p (value: %ld), [1]: %p (value: %ld)\n", coder->index, coder->last_compile_start,
		//coder->dongle_dx->heap.array[0].coder, coder->dongle_dx->heap.array[0].value, coder->dongle_dx->heap.array[1].coder, coder->dongle_dx->heap.array[1].value);
}