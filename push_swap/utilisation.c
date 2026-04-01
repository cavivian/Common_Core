/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilisation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 09:12:04 by cavivian          #+#    #+#             */
/*   Updated: 2026/04/01 14:59:01 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

t_node	*ft_lstlast(t_node *lst)
{
	while (lst != NULL)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (0);
}
