/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 09:30:28 by cavivian          #+#    #+#             */
/*   Updated: 2026/03/16 14:38:46 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	range_chunk(struct Stacks *range, int chunk_size, int count)
{
	t_node	*tmp;
	int min_chunk;
	int max_chunk;
	int	range;

	tmp = range->stack_a;
	min_chunk = find_min(range);
	max_chunk = find_max(range);
	range = (max_chunk - min_chunk + 1) / count;
	min_chunk = min_chunk + range * 
}

void	divide_in_chunk(struct Stacks *change)
{
	int	count;
	t_node	*tmp;
	int	chunk_size;
	int	range;

	count = 0;
	chunk_size = 0;
	tmp = change->stack_a;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	if (count <= 100)
		chunk_size = count / 5;
	else if (count >= 100 && count <= 500)
		chunk_size = count / 11;
	
}