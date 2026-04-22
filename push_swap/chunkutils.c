/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunkutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:05:49 by cavivian          #+#    #+#             */
/*   Updated: 2026/04/22 11:23:43 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_max(struct Stacks *ab)
{
	t_node	*tmp;
	t_node	*max_node;

	if (!ab || !ab->stack_b) // Protezione: se lo stack non esiste o è vuoto
        return (NULL);
	tmp = ab->stack_b;
	max_node = tmp;
	while (tmp)
	{
		if (tmp->index > max_node->index)
			max_node = tmp;
		tmp = tmp->next;
	}
	return (max_node);
}

void	push_back_to_a(struct Stacks *b_to_a)
{
	int		size;
	int		position;
	t_node	*max_node;

	while (b_to_a->stack_b != NULL)
	{
		max_node = find_max(b_to_a);
		size = ft_lstsize(b_to_a->stack_b);
		position = get_position(b_to_a->stack_b, max_node);
		if (position <= size / 2)
		{
			while (b_to_a->stack_b != max_node)
				move_rb(b_to_a);
		}
		else
		{
			while (b_to_a->stack_b != max_node)
				move_rrb(b_to_a);
		}
		move_pa(b_to_a);
	}
}
/* void    push_back_to_a(struct Stacks *b_to_a)
{
    int i = 0;
    while (b_to_a->stack_b != NULL)
    {
        fprintf(stderr, "Giro %d - Cima B: %p (Indice: %d)\n", i++, (void*)b_to_a->stack_b, b_to_a->stack_b->index);
        
        if (i > 100) { // Freno d'emergenza Audi
            fprintf(stderr, "LOOP INFINITO RILEVATO! Esco per sicurezza.\n");
            break;
        }
        
        // Per ora, prova a fare solo pa per vedere se si svuota
        move_pa(b_to_a);
    }
} */

int	get_position(t_node *stack, t_node *i)
{
	int	position;

	position = 0;
	while (stack)
	{
		while (stack == i)
			return (position);
		position++;
		stack = stack->next;
	}
	return (-1);
}

		void	push_minichunk_to_b(struct Stacks *a_to_b, int range)
{
	int		i;
	t_node	*tmp;

	i = 0;
	while (a_to_b->stack_a != NULL)
	{
		tmp = a_to_b->stack_a;
		if (!tmp)
			break;
		if (tmp->index <= i)
		{
			move_pb(a_to_b);
			i++;
		}
		else if (tmp->index <= (i + range))
		{
			move_pb(a_to_b);
			move_rb(a_to_b);
			i++;
		}
		else
			move_ra(a_to_b);
	}
}
