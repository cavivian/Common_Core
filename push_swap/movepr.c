/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movepr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:57:24 by camilla           #+#    #+#             */
/*   Updated: 2026/04/27 10:07:14 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_pa(struct Stacks *pa)
{
	t_node	*tmp;

	if (pa->stack_b == NULL)
		return ;
	tmp = pa->stack_b;
	pa->stack_b = pa->stack_b->next;
	tmp->next = pa->stack_a;
	pa->stack_a = tmp;
	write (1, "pa\n", 3);
}

void	move_pb(struct Stacks *pb)
{
	t_node	*tmp;

	if (pb->stack_a == NULL)
		return ;
	tmp = pb->stack_a;
	pb->stack_a = pb->stack_a->next;
	tmp->next = pb->stack_b;
	pb->stack_b = tmp;
	write(1, "pb\n", 3);
}

void	move_ra(struct Stacks *ra)
{
	t_node	*tmp;
	t_node	*ultimo;

	if (ra->stack_a == NULL || ra->stack_a->next == NULL)
		return ;
	tmp = ra->stack_a;
	ra->stack_a = ra->stack_a->next;
	ultimo = ra->stack_a;
	while (ultimo->next != NULL)
		ultimo = ultimo->next;
	ultimo->next = tmp;
	tmp->next = NULL;
	write (1, "ra\n", 3);
}

void	move_rb(struct Stacks *rb)
{
	t_node	*tmp;
	t_node	*ultimo;

	if (rb->stack_b == NULL || rb->stack_b->next == NULL)
		return ;
	tmp = rb->stack_b;
	ultimo = rb->stack_b;
	while (ultimo->next != NULL)
		ultimo = ultimo->next;
	rb->stack_b = tmp->next;
	ultimo->next = tmp;
	tmp->next = NULL;
	write (1, "rb\n", 3);
}

void	move_rr(struct Stacks *rr)
{
	t_node	*tmp;
	t_node	*ultimo;

	if (rr->stack_a && rr->stack_a->next)
	{
		tmp = rr->stack_a;
		rr->stack_a = rr->stack_a->next;
		ultimo = rr->stack_a;
		while (ultimo->next != NULL)
			ultimo = ultimo->next;
		ultimo->next = tmp;
		tmp->next = NULL;
	}
	if (rr->stack_b && rr->stack_b->next)
	{
		tmp = rr->stack_b;
		rr->stack_b = rr->stack_b->next;
		ultimo = rr->stack_b;
		while (ultimo->next != NULL)
			ultimo = ultimo->next;
		ultimo->next = tmp;
		tmp->next = NULL;
	}
	write (1, "rr\n", 3);
}
