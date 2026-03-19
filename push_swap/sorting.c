/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:02:19 by camilla           #+#    #+#             */
/*   Updated: 2026/03/18 10:44:13 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(struct Stacks *ba)
{
	t_node	*tmp;
	int		first;
	int		second;
	int		third;

	tmp = ba->stack_a;
	first = tmp->value;
	second = tmp->next->value;
	third = tmp->next->next->value;
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

void	sort_four(struct Stacks *aab)
{
	t_node	*tmp;
	t_node	*min;

	tmp = aab->stack_a;
	if (sort_check(aab))
		return ;
	min = find_min(aab);
	while (aab->stack_a->value != min->value)
		move_ra(aab);
	move_pb(aab);
	sort_three(aab);
	move_pa(aab);
}

void	sort_five(struct Stacks *bba)
{
	t_node	*tmp;
	t_node	*min;

	tmp = bba->stack_a;
	if (sort_check(bba))
		return ;
	min = find_min(bba);
	while (bba->stack_a->value != min->value)
		move_ra(bba);
	move_pb(bba);
	min = find_min(bba);
	while (bba->stack_a->value != min->value)
		move_ra(bba);
	move_pb(bba);
	sort_three(bba);
	move_pa(bba);
	move_pa(bba);
}

void	sort(int argc, struct Stacks *_a_b)
{
	argc = argc - 1; // per eliminare il conteggio del nome del file
	if (sort_check(_a_b))
		return ;
	if (argc == 2)
		move_sa(_a_b);
	else if (argc == 3)
		sort_three(_a_b);
	else if (argc == 4)
		sort_four(_a_b);
	else if (argc == 5)
		sort_five(_a_b);
}
