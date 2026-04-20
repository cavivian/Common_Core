/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 15:23:33 by camilla           #+#    #+#             */
/*   Updated: 2026/04/20 10:59:36 by cavivian         ###   ########.fr       */
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

t_node	*ft_parse(char **argv, int argc)
{
	int		i;
	long	tmp;
	t_node	*stack_a;

	stack_a = NULL;
	i = 1;
	/* printf("%d", ft_lstsize(stack)); */
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (error_exit(&stack_a));
		tmp = ft_atoi(argv[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
			return (error_exit(&stack_a));
		if (check_duplicate(stack_a, (int)tmp))
			return (error_exit(&stack_a));
		ft_lstadd_back(&stack_a, ft_lstnew((int)tmp));
		i++;
	}
	return (stack_a);
}
