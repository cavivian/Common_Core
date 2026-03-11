/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:41:31 by camilla           #+#    #+#             */
/*   Updated: 2026/03/10 19:17:51 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void move_sa(struct Stacks *sa)
{
    if (sa->stack_a == NULL || sa->stack_a->next == NULL) // controllo se abbiamo almeno due nodi nello stack
        return ;
    // salvataggio dei nodi temporanei
    t_node *first = sa->stack_a;  // punta al primo nodo della lista, questo verrà scambiato con il secondo
    t_node *second = first->next; // punta al nodo successivo di first
    t_node *third = second->next; // punta al nodo successivo di second
    // modifica dei collegamenti
    first->next = third; // il vecchio primo punta al terzo
    second->next = first; // il vecchio secondo diventa il nuovo top
    sa->stack_a = second; // aggiornamento del top nello stack
    write (1, "sa\n", 3);
}

void move_sb(struct Stacks *sb)
{
    if (sb->stack_b == NULL || sb->stack_b->next == NULL)
        return ;
    t_node *first = sb->stack_b;
    t_node *second = first->next;
    t_node *third =second->next;

    first->next = third;
    second->next = first;
    sb->stack_b = second;
    write (1, "sb\n", 3);
}

void move_ss(struct Stacks *ss)
{
    if (ss->stack_a && ss->stack_a->next)
    {
        t_node *first_sa = ss->stack_a;
        t_node *second_sa = first_sa->next;
        t_node *third_sa = second_sa->next;
        first_sa->next = third_sa;
        second_sa->next = first_sa;
        ss->stack_a = second_sa;
    }
    if (ss->stack_b && ss->stack_b->next)
    {
        t_node  *first_sb = ss->stack_b;
        t_node  *second_sb = first_sb->next;
        t_node  *third_sb = second_sb->next;
        first_sb->next = third_sb;
        second_sb->next = first_sb;
        ss->stack_b = second_sb;
    }
    write(1, "ss\n", 3);
}
