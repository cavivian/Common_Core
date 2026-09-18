/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:01:38 by cavivian          #+#    #+#             */
/*   Updated: 2026/09/18 17:04:21 by cavivian         ###   ########.fr       */
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
		return (NULL);
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

t_heap	*push_into_the_heap(t_heap *heap, t_wait_node node)
{
	int	i;

	if (heap->size <= heap->current_size)
		return (NULL);
	heap->current_size++;
	i = heap->current_size -1;
	heap->array[i] = node;
	while (i != 0 && heap->array[heap_father(i)].value > heap->array[i].value)
	{
		ft_swap(&heap->array[heap_father(i)], &heap->array[i]);
		i = heap_father(i);
	}
	return (heap);
}

void decreaseKey(struct MinHeap *h, int i, int new_val)
{
    h->harr[i] = new_val;
    while (i != 0 && h->array[parent(i)] > h->array[i])
    {
        swap(&h->array[i], &h->array[parent(i)]);
        i = parent(i);
    }
}

// Method to remove minimum element (or root) from min heap
int extractMin(t_heap *h)
{
    if (h->size <= 0)
        return INT_MAX;
    if (h->size == 1)
    {
        h->size--;
        return h->array[0];
    }

    // Store the minimum value, and remove it from heap
    int root = h->array[0];
    h->array[0] = h->array[h->size - 1];
    h->size--;
    MinHeapify(h, 0);

    return root;
}

// This function deletes key at index i.
void deleteKey(struct MinHeap *h, int i)
{
    decreaseKey(h, i, INT_MIN);
    extractMin(h);
}