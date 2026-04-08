/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:13:10 by cavivian          #+#    #+#             */
/*   Updated: 2026/04/08 09:11:48 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	easyswap(struct nodo *a_b)
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

void	ft_indexing(struct nodo *a)
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

void	push_swap(struct nodo *aabb)
{
	t_node	*tmp;
	int		size;

	tmp = aabb->stack_a;
	size = ft_lstsize(tmp);
	ft_indexing(aabb);
	while (size <= 5)
		easyswap(aabb);
	while (size > 5 && !sort_check(aabb))
		divide_in_chunk(aabb);
	size++;
}

int	main( int argc, char *argv[])
{
	struct nodo	*stack;

	stack.stack_a = ft_parse(*stack, argv);
	stack.stack_b = NULL;
	if (argc < 2 || !stack.stack_a)
		return (0);
	push_swap(&stack);
	free_stack(&stack.stack_a);
	return (0);
}
