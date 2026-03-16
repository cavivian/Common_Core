/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunkutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:05:49 by cavivian          #+#    #+#             */
/*   Updated: 2026/03/16 10:07:33 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(struct Stacks *ab)
{
	t_node	*tmp;
	t_node	*max_node;
	int		max_value;

	tmp = ab->stack_a;
	max_node = tmp;
	max_value = tmp->value;
	while (tmp->value != NULL)
	{
		if (tmp->value > max_value)
		{
			max_value = tmp->value;
			max_node = tmp;
		}
		tmp = tmp->next;
	}
	return (max_node);
}
