/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:11:56 by camilla           #+#    #+#             */
/*   Updated: 2026/04/20 10:59:46 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int value)
{
	t_node	*list;

	list = malloc(sizeof(t_node));
	if(!list)
		return(NULL);
	list->value = value;
	list->next = NULL;
	return (list);
}

int	check_duplicate(t_node *stack, int num)
{
	if(!stack)
		return(0);
	while (stack)
	{
		if (stack->value == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*temp;

	if (!*lst)
		*lst = new;
	else
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*current;

	if (!*stack || !stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

t_node	*error_exit(t_node **stack)
{
	free_stack(stack);
	write (2, "Error\n", 7);
	return (NULL);
}
