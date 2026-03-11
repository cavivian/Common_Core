/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:41:31 by camilla           #+#    #+#             */
/*   Updated: 2026/03/11 12:13:31 by cavivian         ###   ########.fr       */
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

void	move_rra(struct Stacks *rra)
{
	t_node	*primo; // puntatore per scorrere
	t_node	*ultimo;

	primo = rra->stack_a;
	if (rra->stack_a == NULL || rra->stack_a->next == NULL) // controllo che esista lo stack e che abbia piu' di un nodo
		return (0);
	while (primo->next->next != NULL) // scorro fino a trovare il penultimo
		primo = primo->next; // nodo successivo a primo
	ultimo = primo->next; // stacco l'ultimo nodo e lo aggiorno
	primo->next = NULL;
	ultimo->next = rra->stack_a; // metto l'ultimo in testa
	rra->stack_a = ultimo;
	write(1, "rra\n", 4);
}
