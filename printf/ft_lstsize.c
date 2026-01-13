/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 08:47:55 by cavivian          #+#    #+#             */
/*   Updated: 2025/12/16 11:23:53 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		i;

	temp = lst;
	i = 0;
	if (temp == NULL)
		return (0);
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

/*int	main(void)
{
	t_list *lst;

	lst = NULL;

    // Collegamento dei nodi
    node1->next = node2;
    node2->next = NULL; // ultimo nodo

    // Puntatore all'inizio della lista
    lst = node1;

    // Chiamata alla funzione ft_lstsize
    size = ft_lstsize(lst);

    // Stampa del risultato
    printf("La lista contiene %d nodi\n", size);

    // Pulizia della memoria
    free(node1);
    free(node2);

    return 0;
}*/
