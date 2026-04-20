/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:41:00 by camilla           #+#    #+#             */
/*   Updated: 2026/04/20 10:56:12 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min(struct Stacks *ab)
{
	t_node	*tmp;
	t_node	*min_node;
	int		min_index;

	tmp = ab->stack_a;
	min_node = tmp;
	min_index = tmp->index;
	while (tmp != NULL)
	{
		if (tmp->value < min_index)
		{
			min_index = tmp->index;
			min_node = tmp;
		}
		tmp = tmp->next;
	}
	return (min_node);
}

int	sort_check( struct Stacks *ab)
{
	t_node	*tmp;

	tmp = ab->stack_a;
	if (ab->stack_a == NULL || ab->stack_a->next == NULL)
		return (1); // return 1 perchè è ovvio che sia già ordinato
	while (tmp->next != NULL)
	{
		if (tmp->index < tmp->next->index)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

void	last_sort(struct Stacks *ba)
{
	move_sa(ba);
	move_rra(ba);
}

int	ft_lstsize(t_node *lst)
{
	t_node	*temp;
	int		i;

	temp = lst;
	i = 0;
	if (temp == NULL)
		return (0);
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
