/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:35:46 by cavivian          #+#    #+#             */
/*   Updated: 2026/04/17 14:07:07 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef struct nodo{
	void  *content;
	int value;
	int	index;
	struct nodo *next;
	struct nodo *stack_a;
	struct nodo *stack_b;
}t_node;

void move_sa(struct nodo *sa);
void move_sb(struct nodo *sb);
void move_ss(struct nodo *ss);
void move_pa(struct nodo *pa);
void move_pb(struct nodo *pb);
void move_ra(struct nodo *ra);
void move_rb(struct nodo *rb);
void move_rra(struct nodo *rra);
void move_rrb(struct nodo *rrb);
void move_rrr(struct nodo *rrr);
void	easyswap(struct nodo *a_b);
void	push_swap(struct nodo *aabb);
void sort_three(struct nodo *ba);
void sort_four(struct nodo *aab);
void sort_five(struct nodo *bba);
void	sort(struct nodo *_a_b);
t_node  *find_min(struct nodo *ab);
int is_number(char *str);
int	 sort_check( struct nodo *ab);
void last_sort(struct nodo *ba);
int divide_in_chunk(struct nodo *change);
t_node	*find_max(struct nodo *ab);
int    check_duplicate(t_node *stack, int num);
t_node	*ft_lstnew(void *content);
tf_node	*ft_parse(struct nodo *stack, char **argv, int argc);
void	ft_lstadd_back(t_node **lst, t_node *new);
void	free_stack(t_node **stack);
t_node	*error_exit(t_node **stack);
int	ft_lstsize(t_node *lst);
int	get_position(t_node *stack, t_node *i);
void	push_back_to_a(struct nodo *b_to_a);
int	ft_atoi(const char *str);
t_node	*ft_lstlast(t_node *lst);
int	ft_isdigit(int c);


#endif