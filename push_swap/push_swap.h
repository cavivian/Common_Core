/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:35:46 by cavivian          #+#    #+#             */
/*   Updated: 2026/03/06 10:28:20 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

typedef struct nodo{
	int value;
	struct nodo *next;
}t_node;

struct Stacks
{
	t_node *stack_a;
	t_node *stack_b;
};



#endif