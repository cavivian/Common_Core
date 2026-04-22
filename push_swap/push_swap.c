/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:13:10 by cavivian          #+#    #+#             */
/*   Updated: 2026/04/22 11:57:51 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	easyswap(struct Stacks *a_b)
{
	t_node	*tmp;

	tmp = a_b->stack_a;
	if (!tmp->index || !a_b)
		return ;
	if (tmp->index <= 5)
		sort_check(a_b);
	if (!sort_check(a_b) && tmp->index <= 5)
		sort(a_b);
}

void	ft_indexing(struct Stacks *a)
{
	t_node	*current;
	t_node	*compare;
	int		count;

	current = a->stack_a;
	while (current != NULL)
	{
		count = 0;
		compare = a->stack_a;
		while (compare != NULL)
		{
			if (compare->value < current->value)
				count++;
			compare = compare->next;
		}
		current->index = count;
		current = current->next;
	}
}

void    push_swap(struct Stacks *aabb)
{
    int     size;
	int		range;

    ft_indexing(aabb); // 1. Prima di tutto diamo gli indici
    size = ft_lstsize(aabb->stack_a);

    if (sort_check(aabb)) // Se è già ordinato, non fare nulla
        return ;

    if (size <= 5)
    {
        easyswap(aabb); // Gestisce 2, 3, 4 o 5 numeri
    }
    else
    {
        // LOGICA CHUNK (Niente while qui!)
        range = divide_in_chunk(aabb); // Calcola il range
        push_minichunk_to_b(aabb, range);  // Svuota A in B (ha già i suoi while dentro)
        push_back_to_a(aabb);              // Riporta tutto in A (ha già i suoi while)
    }
}

int	main( int argc, char *argv[])
{
	struct Stacks	stack;
	char **args;
	int	is_split;

	is_split = 0;
	stack.stack_a = NULL;
	stack.stack_b = NULL;
	if (argc < 2)
		return (0);
	if(argc == 2)
	{
		args = ft_split(argv[1], ' ');
		is_split = 1;
	}
	else
		args = argv + 1;
	stack.stack_a = ft_parse(args);
	if (is_split)
        free_array(args);
	if (!stack.stack_a)
		return (0);
	push_swap(&stack);
	free_stack(&stack.stack_a);
	return (0);
}
