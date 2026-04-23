/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:13:10 by cavivian          #+#    #+#             */
/*   Updated: 2026/04/23 12:17:28 by cavivian         ###   ########.fr       */
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

void	push_swap(struct Stacks *aabb)
{
	int		size;
	int		range;

	ft_indexing(aabb);
	size = ft_lstsize(aabb->stack_a);
	if (sort_check(aabb))
		return ;
	if (size <= 5)
	{
		easyswap(aabb);
	}
	else
	{
		range = divide_in_chunk(aabb);
		push_minichunk_to_b(aabb, range);
		push_back_to_a(aabb);
	}
}

int	main(int argc, char *argv[])
{
	struct Stacks	stack;
	char			**args;
	char			*full_string;

	stack.stack_a = NULL;
	stack.stack_b = NULL;
	if (argc < 2)
		return (0);
	full_string = join_args(argc, argv);
	if (!full_string)
		return (write(2, "Error\n", 6), 1);
	args = ft_split(full_string, ' ');
	free(full_string); // Non ci serve più
	if (!args || !args[0])
	{
		if (args) free_array(args);
		return (write(2, "Error\n", 6), 1);
	}
	stack.stack_a = ft_parse(args);
	free_array(args);
	if (!stack.stack_a)
		return (0);
	push_swap(&stack);
	free_stack(&stack.stack_a);
	return (0);
}
