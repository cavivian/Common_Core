/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:01:38 by cavivian          #+#    #+#             */
/*   Updated: 2026/09/20 15:45:44 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

t_heap	*init_array_heap(int size)
{
	t_heap	*heap;

	heap = malloc(sizeof(t_heap));
	if (!heap)
		return (NULL);
	heap->array = malloc(size * sizeof(t_wait_node));
	if (!heap->array)
	{
		free_heap(heap);
		return (NULL);
	}
	memset(heap->array, 0, size * sizeof(t_wait_node));
	heap->size = size;
	heap->current_size = 0;
	return (heap);
}

void	ft_swap(t_wait_node *a, t_wait_node *b)
{
	t_wait_node	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_heap	*push_into_the_heap(t_heap *heap, t_wait_node *node)
{
	int	i;

	if (heap->size <= heap->current_size)
		return (NULL);
	heap->current_size++;
	i = heap->current_size -1;
	heap->array[i] = *node;
	while (i != 0 && heap->array[heap_father(i)].value > heap->array[i].value)
	{
		ft_swap(&heap->array[heap_father(i)], &heap->array[i]);
		i = heap_father(i);
	}
	return (heap);
}

void decreaseKey(t_heap *heap, int i, t_wait_node new_val)
{
    heap->array[i] = new_val;
    while (i != 0 && &heap->array[heap_father
		(i)] > &heap->array[i])
    {
        ft_swap(&heap->array[i], &heap->array[heap_father(i)]);
        i = heap_father(i);
    }
}

int delete_max_priority_node(t_heap *heap, t_wait_node *extract_node)
{
	if (heap == NULL || heap->current_size <= 0)
		return (1);
    if (heap->current_size == 1)
    {
        heap->current_size--;
        *extract_node = heap->array[0];
        return (0);
    }

    // Store the value with max priority, and remove it from heap
    *extract_node = heap->array[0];
    heap->array[0] = heap->array[heap->current_size - 1];
    heap->current_size--;
    Minheapify(heap, 0);

    return 0;
}

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
		if (left_son < heap->current_size &&
			heap->array[left_son].value > heap->array[best].value)
			best = left_son;
		if (right_son < heap->current_size &&
			heap->array[right_son].value > heap->array[best].value)
			best = right_son;
		if (best == index)
			return ;
		else
		{
			ft_swap(&heap->array[index], &heap->array[best]);
			index  = best;
		}
	}
	//push_into_the_heap(heap, node);
}

// This function deletes key at index i.
void deleteKey(t_heap *heap, int i)
{
    decreaseKey(heap, i, INT_MIN);
    extractMin(heap);
}