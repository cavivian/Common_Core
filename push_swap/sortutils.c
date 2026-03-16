/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingtwo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:41:00 by camilla           #+#    #+#             */
/*   Updated: 2026/03/15 19:13:17 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min(struct Stacks *ab)
{
    t_node  *tmp;
    t_node  *min_node;
    int min_value;

    tmp = ab->stack_a;
    min_node =  tmp;
    min_value = tmp->value;
    while (tmp->value != NULL)
    {
        if (tmp->value < min_value)
        {
            min_value = tmp->value;
            min_node = tmp;
        }
        tmp = tmp->next;
    }
    return (min_node);
}
int	sort_check( struct Stacks *ab)
{
	t_node	*tmp;

	tmp = ab->stack_a;
	if (ab->stack_a == NULL || ab->stack_a->next == NULL) // controllo che esiste lo stack e che ci sia piu' di un nodo
		return (1); // return 1 perchè è ovvio che sia già ordinato
	while (tmp->next != NULL)
	{
		if (tmp->value < tmp->next->value)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

void	last_sort(struct Stacks *ba)
{
	move_sa(ba);
	move_rra(ba);
}