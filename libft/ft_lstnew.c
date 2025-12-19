/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 08:46:40 by cavivian          #+#    #+#             */
/*   Updated: 2025/12/17 14:44:14 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->content = content;
	list->next = NULL;
	return (list);
}

/*int	main(void)
{
	void*	content = "ciao";
	t_list	*node;

	node = ft_lstnew(&content);
	if (!node)
	{
		printf("Allocazione fallita\n");
		return (1);
	}

	printf("Contenuto del nodo: %d\n", *(int *)node->content);
	if (node->next == NULL)
		printf("Il puntatore next è NULL (corretto)\n");
	else
		printf("Errore: next non è NULL\n");

	free(node);
	return (0);
}*/
