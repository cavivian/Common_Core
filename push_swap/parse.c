/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 15:23:33 by camilla           #+#    #+#             */
/*   Updated: 2026/04/22 12:05:04 by cavivian         ###   ########.fr       */
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

t_node	*ft_parse(char **argv)
{
	int		i;
	long	tmp;
	t_node	*stack_a;
	t_node	*new_node;

	stack_a = NULL;
	i = 0;
	/* printf("%d", ft_lstsize(stack)); */
	while (argv[i])
	{
		if (!is_number(argv[i]))
			return (error_exit(&stack_a));
		tmp = ft_atoi(argv[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
			return (error_exit(&stack_a));
		if (check_duplicate(stack_a, (int)tmp))
			return (error_exit(&stack_a));
		new_node = ft_lstnew((int)tmp);
		if(!new_node)
			return(error_exit(&stack_a));
		ft_lstadd_back(&stack_a, new_node);
		i++;
	}
	return (stack_a);
}

void	free_array(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
	{
		free(args[i]); // Libera la stringa "4894"
		i++;
	}
	free(args); // Libera l'array che conteneva i puntatori
}