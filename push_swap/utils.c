/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:11:56 by camilla           #+#    #+#             */
/*   Updated: 2026/03/24 09:45:19 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->content = content;
	list->next = NULL;
	return (list);
}

int    check_duplicate(t_node *stack, int num)
{
    while (stack != NULL)
    {
        if (stack->value == num)
            return (1);
        stack = stack->next;
    }
    return (0);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

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
	t_node *tmp;
	t_node *current;

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
	fre_stack(&stack);
	write (2, "Error\n", 7);
	return (NULL);
}