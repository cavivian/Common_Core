/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 08:53:22 by cavivian          #+#    #+#             */
/*   Updated: 2025/12/16 11:52:32 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (!lst -> next)
			return (lst);
		lst = lst->next;
	}
	return (0);
}

/*int	main(void)
{
	t_list *lst = ft_lstnew((void *)1);
	lst->next = ft_lstnew((void *)2);
	lst->next->next = ft_lstnew((void *)3);
    t_list *lastElement = ft_lstlast(lst);
    printf("%d\n", (int)(intptr_t)lastElement->content);
}*/
