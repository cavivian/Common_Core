/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 15:23:33 by camilla           #+#    #+#             */
/*   Updated: 2026/04/08 08:58:09 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

t_node	*ft_parse(struct nodo *stack, char **argv)
{
	int		i;
	long	tmp;

	stack = stack->stack_a;
	i = 1;
	while (i < ft_lstsize(stack))
	{
		if (!is_number(argv[i]))
			return (error_exit(&stack));
		tmp = ft_atoi(argv[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
			return (error_exit(&stack));
		if (check_duplicate(stack, (int)tmp))
			return (error_exit(&stack));
		ft_lstadd_back(&stack, ft_lstnew((void *)tmp));
		i++;
	}
	return (stack);
}
