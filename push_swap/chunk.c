/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 09:30:28 by cavivian          #+#    #+#             */
/*   Updated: 2026/04/23 08:18:52 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	divide_in_chunk(struct Stacks *change)
{
	int		count;
	t_node	*tmp;
	int		chunk_size;

	count = 0;
	chunk_size = 0;
	tmp = change->stack_a;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	if (count <= 100 && !sort_check(change))
		chunk_size = count / 5;
	else if (count > 100 && count <= 500 && !sort_check(change))
		chunk_size = count / 11;
	else
		chunk_size = count / 15;
	return (chunk_size);
}
