/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 15:23:33 by camilla           #+#    #+#             */
/*   Updated: 2026/03/22 16:20:25 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_number(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (str[i] == '\0')
        return (0);
    while (str[i] != '\0')
    {
       if (!ft_isdigit(str[i]))
            return(0);
        i++;
    }
    return (1);
}

t_node  *ft_parse(int argc, char **argv)
{
    int i;
    int tmp;
    t_node  *new;
    t_node  *stack = NULL;

    i = 1;
    if(argc < 2)
        return (NULL);
    while (i < argc)
    {
        if (!is_number(argv[i]))
        {
            write (1, "Error\n", 7);
            return (NULL);
        }
        tmp = ft_atoi(argv[i]);
        new = ft_lstnew(tmp);
        ft_lstadd_back(&stack, new);
        i++;
    }
    return (stack);
}
