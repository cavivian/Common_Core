/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:41:31 by camilla           #+#    #+#             */
/*   Updated: 2026/03/12 10:02:04 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_sa(struct Stacks *sa)
{
	t_node	*first;// punta al primo nodo della lista, questo verrà scambiato con il secondo
	t_node	*second;// punta al nodo successivo di first
	t_node	*third;

	if (sa->stack_a == NULL || sa->stack_a->next == NULL) // controllo se abbiamo almeno due nodi nello stack
		return (0);
	// salvataggio dei nodi temporanei
	// punta al nodo successivo di second
    // modifica dei collegamenti
	first = sa->stack_a;
	second = first->next;
	third = second->next;
	first->next = third; // il vecchio primo punta al terzo
	second->next = first; // il vecchio secondo diventa il nuovo top
	sa->stack_a = second; // aggiornamento del top nello stack
	write (1, "sa\n", 3);
}

void	move_sb(struct Stacks *sb)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (sb->stack_b == NULL || sb->stack_b->next == NULL)
		return (0);
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
		return (0);
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
