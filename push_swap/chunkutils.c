/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunkutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:05:49 by cavivian          #+#    #+#             */
/*   Updated: 2026/03/24 11:24:25 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_max(struct Stacks *ab)
{
	t_node	*tmp;
	t_node	*max_node;
	int		max_value;

	tmp = ab->stack_a;
	max_node = tmp;
	max_value = tmp->value;
	while (tmp != NULL)
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

void	push_back_to_a(struct Stacks *b_to_a)
{
	t_node	*tmp;
	t_node	*max;
	int	size;
	int	position;
	
	tmp = b_to_a->stack_b;
	while (tmp != NULL)
	{
		max = find_max(b_to_a);
		size = ft_lstsize(tmp);
		position = get_position(tmp, max);
	if (position <= size / 2)
		while (tmp != max)
			move_rb(b_to_a);
	else
		while (tmp != max)
			move_rrb(b_to_a);
	move_pa(b_to_a);
	}
}

int	get_position(t_node *stack, t_node *i)
{
	int position;

	position = 0;
	while (stack)
	{
		while (stack == i)
			return (position);
		stack = stack->next;
		position++;
	}
	return (position);
}