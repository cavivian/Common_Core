/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilisation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 09:12:04 by cavivian          #+#    #+#             */
/*   Updated: 2026/04/23 09:35:17 by cavivian         ###   ########.fr       */
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
		if (!lst)
			return (NULL);
		while (lst->next != NULL)
			lst = lst->next;
		return (lst);
	}
	return (0);
}
