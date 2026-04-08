/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:02:19 by camilla           #+#    #+#             */
/*   Updated: 2026/04/06 16:41:13 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(struct nodo *ba)
{
	t_node	*tmp;
	int		first;
	int		second;
	int		third;

	tmp = ba->stack_a;
	first = tmp->index;
	second = tmp->next->index;
	third = tmp->next->next->index;
	if (sort_check(ba))
		return ;
	else if (first < third && third < second)
	{
		move_sa(ba);
		move_ra(ba);
	}
	else if (second < first && first < third)
		move_sa(ba);
	else if (second < third && third < first)
		move_rra(ba);
	else if (third < first && first < second)
		move_ra(ba);
	else if (third < second && second < first)
		last_sort(ba);
}

void	sort_four(struct nodo *aab)
{
	t_node	*min;

	if (sort_check(aab))
		return ;
	min = find_min(aab);
	while (aab->stack_a->index != min->index)
		move_ra(aab);
	move_pb(aab);
	sort_three(aab);
	move_pa(aab);
}

void	sort_five(struct nodo *bba)
{
	t_node	*min;

	if (sort_check(bba))
		return ;
	min = find_min(bba);
	while (bba->stack_a->index != min->index)
		move_ra(bba);
	move_pb(bba);
	min = find_min(bba);
	while (bba->stack_a->index != min->index)
		move_ra(bba);
	move_pb(bba);
	sort_three(bba);
	move_pa(bba);
	move_pa(bba);
}

void	sort(struct nodo *_a_b)
{
	int	size;

	size = ft_lstsize(_a_b->stack_a);
	if (sort_check(_a_b))
		return ;
	if (size == 2)
		move_sa(_a_b);
	else if (size == 3)
		sort_three(_a_b);
	else if (size == 4)
		sort_four(_a_b);
	else if (size == 5)
		sort_five(_a_b);
}
