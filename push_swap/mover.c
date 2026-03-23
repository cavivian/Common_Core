/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:01:22 by cavivian          #+#    #+#             */
/*   Updated: 2026/03/22 14:54:02 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*move_rra(struct Stacks *rra)
{
	t_node	*primo; // puntatore per scorrere
	t_node	*ultimo;

	primo = rra->stack_a;
	if (!rra || rra->stack_a == NULL || rra->stack_a->next == NULL) // controllo che esista lo stack e che abbia piu' di un nodo
		return ;
	while (primo->next->next != NULL) // scorro fino a trovare il penultimo
		primo = primo->next; // nodo successivo a primo
	ultimo = primo->next; // stacco l'ultimo nodo e lo aggiorno
	primo->next = NULL;
	ultimo->next = rra->stack_a; // metto l'ultimo in testa
	rra->stack_a = ultimo;
	write(1, "rra\n", 4);
}

void	*move_rrb(struct Stacks *rrb)
{
	t_node	*primo;
	t_node	*ultimo;

	primo = rrb->stack_b;
	if (!rrb || rrb->stack_b == NULL || rrb->stack_b->next == NULL)
		return ;
	while (primo->next->next != NULL)
		primo = primo->next;
	ultimo = primo->next;
	primo->next = NULL;
	ultimo->next = rrb->stack_b;
	rrb->stack_b = ultimo;
	write (1, "rrb\n", 4);
}

void	*move_rrr(struct Stacks *rrr)
{
	t_node	*primo;
	t_node	*ultimo;

	if (!rrr || !rrr->stack_a || !rrr->stack_a->next
		|| !rrr->stack_b  || !rrr->stack_b->next)
		return ; 
	if (rrr->stack_a && rrr->stack_a->next)
	{
		primo = rrr->stack_a;
		while (primo->next->next != NULL)
			primo = primo->next;
		ultimo = primo->next;
		primo->next = NULL;
		ultimo->next = rrr->stack_a;
		rrr->stack_a = ultimo;
	}
	if (rrr->stack_b && rrr->stack_b->next)
	{
		primo = rrr->stack_b;
		while (primo->next->next != NULL)
			primo = primo->next;
		ultimo = primo->next;
		primo->next = NULL;
		ultimo->next = rrr->stack_b;
		rrr->stack_b = ultimo;
	}
	write (1, "rrr\n", 4);
}
