/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:13:10 by cavivian          #+#    #+#             */
/*   Updated: 2026/03/25 14:14:37 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	easyswap(struct Stacks *a_b)
{
	t_node	*tmp;

	tmp = a_b->stack_a;
	if (!tmp->index || !a_b)
		return (NULL);
	if (tmp->index <= 5)
		sort_check(a_b);
	if (!sort_check(a_b) && tmp->index <= 5)
		sort(tmp->index, a_b);
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
	t_node	*tmp;
	int	size;

	tmp = aabb->stack_a;
	size = ft_lstsize(tmp);
	ft_indexing(aabb);
	while (size <= 5)
		easyswap(aabb);
	while (size > 5)
		divide_in_chunk(aabb);
}

int	main( int argc, char *argv[])
{
    printf("Number of arguments: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
    return 0;
}
