/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:41:31 by camilla           #+#    #+#             */
/*   Updated: 2026/04/23 09:20:16 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_sa(struct Stacks *sa)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (sa->stack_a == NULL || sa->stack_a->next == NULL)
		return ;
	first = sa->stack_a;
	second = first->next;
	third = second->next;
	first->next = third;
	second->next = first;
	sa->stack_a = second;
	write (1, "sa\n", 3);
}

void	move_sb(struct Stacks *sb)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (sb->stack_b == NULL || sb->stack_b->next == NULL)
		return ;
	first = sb->stack_b;
	second = first->next;
	third = second->next;
	first->next = third;
	second->next = first;
	sb->stack_b = second;
	write (1, "sb\n", 3);
}

void	move_ss(struct Stacks *ss)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!ss)
		return ;
	if (ss->stack_a && ss->stack_a->next)
	{
		first = ss->stack_a;
		second = first->next;
		third = second->next;
		first->next = third;
		second->next = first;
		ss->stack_a = second;
	}
	if (ss->stack_b && ss->stack_b->next)
	{
		first = ss->stack_b;
		second = first->next;
		third = second->next;
		first->next = third;
		second->next = first;
		ss->stack_b = second;
	}
	write(1, "ss\n", 3);
}
