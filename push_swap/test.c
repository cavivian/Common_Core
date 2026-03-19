/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:13:51 by cavivian          #+#    #+#             */
/*   Updated: 2026/03/18 11:46:50 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h" // adatta all'header tuo

void	move_sa(struct Stacks *sa)
{
	t_node	*first;// punta al primo nodo della lista, questo verrà scambiato con il secondo
	t_node	*second;// punta al nodo successivo di first
	t_node	*third;

	if (sa->stack_a == NULL || sa->stack_a->next == NULL) // controllo se abbiamo almeno due nodi nello stack
		return ;
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

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	print_stack(t_node *stack, char *name)
{
	printf("Stack %s: ", name);
	while (stack)
	{
		printf("%d -> ", stack->value);
		stack = stack->next;
	}
	printf("NULL\n");
}

int	main(int argc, char **argv)
{
	struct Stacks	stacks;
	t_node			*node;
	int				i;

	if (argc < 2)
	{
		printf("Usage: %s <num1> <num2> ...\n", argv[0]);
		return (1);
	}
	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	i = argc - 1;
	while (i >= 1)
	{
		node = new_node(atoi(argv[i]));
		node->next = stacks.stack_a;
		stacks.stack_a = node;
		i--;
	}
	printf("--- Before move_pa ---\n");
	print_stack(stacks.stack_a, "A");
	print_stack(stacks.stack_b, "B");
	move_sa(&stacks);
	printf("--- After move_pa ---\n");
	print_stack(stacks.stack_a, "A");
	print_stack(stacks.stack_b, "B");
	return (0);
}