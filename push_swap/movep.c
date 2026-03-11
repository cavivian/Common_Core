/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:57:24 by camilla           #+#    #+#             */
/*   Updated: 2026/03/11 12:02:57 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_pa(struct Stacks *pa)
{
	t_node	*tmp;

	if (pa->stack_b == NULL || pa->stack_b->next == NULL)
		return (0);
	tmp = pa->stack_b;
	pa->stack_b = pa->stack_b->next; // per aggiornare stack-b
	tmp->next = pa->stack_a;
	pa->stack_a = tmp;
	write (1, "pa\n", 3);
}

void	move_pb(struct Stacks *pb)
{
	t_node	*tmp;

	if (pb->stack_a == NULL || pb->stack_a->next == NULL)
		return (0);
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

	if (ra->stack_a == NULL || ra->stack_a->next == NULL) // previene errori di accesso a memoria non valida, controlla lista vuota e con un solo elemento
		return (0);
	tmp = ra->stack_a; // punta al primo nodo della lista, si salva perchè dovrà andare in coda dopo la rotazione
	ra->stack_a = ra->stack_a->next; // la testa dello stack diventa il secondo nodo, perchè [1] deve andare in fondo
	ultimo = ra->stack_a; // serve a trovare la fine della lista
	while (ultimo->next != NULL)
		ultimo = ultimo->next; // qui ultimo punta a [3]
	ultimo->next = tmp; //coolegamento della vecchia testa in fondo
	tmp->next = NULL; //ora tmp è l'ultimo nodo e il suo next deve essere NULL
	write (1, "ra\n", 3);
}

void	move_rb(struct Stacks *rb)
{
	t_node	*tmp;
	t_node	*ultimo;

	if (rb->stack_b == NULL || rb->stack_b->next == NULL)
		return (0);
	tmp = rb->stack_b;
	rb->stack_b = rb->stack_b->next;
	ultimo = rb->stack_b;
	while (ultimo->next != NULL)
		ultimo = ultimo->next;
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
