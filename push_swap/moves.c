/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:41:31 by camilla           #+#    #+#             */
/*   Updated: 2026/04/06 16:40:25 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_sa(struct nodo *sa)
{
	t_node	*first;// punta al primo nodo della lista, questo verrà scambiato con il secondo
	t_node	*second;// punta al nodo successivo di first
	t_node	*third;

	if (sa->stack_a == NULL || sa->stack_a->next == NULL) // controllo se abbiamo almeno due nodi nello stack
		return ;
	first = sa->stack_a;
	second = first->next;
	third = second->next;
	first->next = third; // il vecchio primo punta al terzo
	second->next = first; // il vecchio secondo diventa il nuovo top
	sa->stack_a = second; // aggiornamento del top nello stack
	write (1, "sa\n", 3);
}

void	move_sb(struct nodo *sb)
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

void	move_ss(struct nodo *ss)
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
