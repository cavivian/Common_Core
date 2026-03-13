/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:13:10 by cavivian          #+#    #+#             */
/*   Updated: 2026/03/13 14:12:13 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_check(int argc, struct Stacks *ab)
{
	t_node	*tmp;

	tmp = ab->stack_a;
	if (ab->stack_a == NULL || ab->stack_a->next == NULL) // controllo che esiste lo stack e che ci sia piu' di un nodo
		return (0);
	while (tmp->next != NULL && tmp->value < tmp->next->value)
	{
		tmp = tmp->next;
		if (tmp->value < tmp->next->value)
		{
			
		}
	}
	return (1);
}

void	easyswap(int argc, struct Stacks *a_b)
{
	sort_check(argc, a_b);
}

int push_swap(struct Stacks, int *argc, char *argv)
{
	int	i;
	int	conversion;
	
	i = 1;
	while (i < argc)
	{
		conversion = ft_atoi(argv);
		i++;
	}

}
int main( int *argc[], char *argv[])
{
	struct Stacks ;
	if (argc <= 0 || !argv)
		write(1, "Error", sizeof(char));
	if (argc <= 5)
		easyswap(0, 0);	
}

