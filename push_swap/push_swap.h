/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:35:46 by cavivian          #+#    #+#             */
/*   Updated: 2026/03/15 19:24:19 by camilla          ###   ########.fr       */
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
void move_rra(struct Stacks *rra);
void move_rrb(struct Stacks *rrb);
void move_rrr(struct Stacks *rrr);
void easyswap(int argc, struct Stacks *a_b);
int push_swap(struct Stacks, int *argc, char *argv);
void sort_three(struct Stacks *ba);
void sort_four(struct Stacks *aab);
void sort_five(struct Stacks *bba);
int sort(int argc, struct Stacks *_a_b);
int find_min(struct Stacks *ab);
int	sort_check( struct Stacks *ab);
void last_sort(struct Stacks *ba);


#endif