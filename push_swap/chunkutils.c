/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunkutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:05:49 by cavivian          #+#    #+#             */
/*   Updated: 2026/04/20 15:19:50 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_max(struct Stacks *ab)
{
	t_node	*tmp;
	t_node	*max_node;
	int		max_value;

	tmp = ab->stack_b;
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
	int		size;
	int		position;

	tmp = b_to_a->stack_b;
	while (b_to_a->stack_b != NULL)
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
	int	position;

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

void	push_minichunk_to_b(struct Stacks *a_to_b, int range)
{
	int		i;

	i = 0;
	while (a_to_b->stack_a != NULL)
	{
		t_node	*tmp;
		
		tmp = a_to_b->stack_a;
		printf("DEBUG: cima_index: %d, i: %d, range: %d\n", tmp->index, i, range);
		if (tmp->index <= i)
		{
			move_pb(a_to_b);
			i++;
		}
		else if (tmp->index <= (i + range))
		{
			move_pb(a_to_b);
			move_rb(a_to_b);
			i++;
		}
		else
			move_ra(a_to_b);
	}
}
