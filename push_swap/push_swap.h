/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:35:46 by cavivian          #+#    #+#             */
/*   Updated: 2026/04/01 09:54:19 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

typedef struct nodo{
	void  *content;
	int value;
	int	index;
	struct nodo *next;
}t_node;

typedef struct Stacks
{
	t_node *stack_a;
	t_node *stack_b;
}stack;

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
void	easyswap(struct Stacks *a_b);
void	push_swap(struct Stacks *aabb);
void sort_three(struct Stacks *ba);
void sort_four(struct Stacks *aab);
void sort_five(struct Stacks *bba);
void	sort(struct Stacks *_a_b);
t_node  *find_min(struct Stacks *ab);
int is_number(char *str);
int	 sort_check( struct Stacks *ab);
void last_sort(struct Stacks *ba);
int divide_in_chunk(struct Stacks *change);
t_node	*find_max(struct Stacks *ab);
int    check_duplicate(t_node *stack, int num);
t_node	*ft_lstnew(void *content);
t_node  *ft_parse(int argc, char **argv);
void	ft_lstadd_back(t_node **lst, t_node *new);
void	free_stack(t_node **stack);
t_node	*error_exit(t_node **stack);
int	ft_lstsize(t_node *lst);
int	get_position(t_node *stack, t_node *i);
void	push_back_to_a(struct Stacks *b_to_a);
int	ft_atoi(const char *str);
t_node	*ft_lstlast(t_node *lst);
int	ft_isdigit(int c);

#endif