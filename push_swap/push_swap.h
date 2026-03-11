/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:35:46 by cavivian          #+#    #+#             */
/*   Updated: 2026/03/10 19:17:45 by camilla          ###   ########.fr       */
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

typedef struct Stacks
{
	t_node *stack_a;
	t_node *stack_b;
};

void move_sa(struct Stacks *sa);
void move_sb(struct Stacks *sb);
void move_ss(struct Stacks *ss);
void move_pa(struct Stacks *pa);
void move_pb(struct Stacks *pb);
void move_ra(struct Stacks *ra);
void move_rb(struct Stacks *rb);



#endif