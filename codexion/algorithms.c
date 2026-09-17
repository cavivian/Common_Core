/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 11:18:30 by camilla           #+#    #+#             */
/*   Updated: 2026/09/17 17:39:24 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	has_fifo_priority(t_wait_node *a, t_wait_node *b)
{
	return (a->request_time < b->request_time);
}

int	has_edf_priority(t_wait_node *a, t_wait_node *b)
{
	long			save_a;
	long			save_b;

	save_a = a->coder->last_compile_start + a->coder->quantum->config.burnout;
	save_b = b->coder->last_compile_start + b->coder->quantum->config.burnout; // calcoli per la deadline di burnout
	return (save_a < save_b);
}


int	has_priority(t_wait_node *a, t_wait_node *b)
{
	if (a->coder->quantum->config.algorithm == FIFO)
		return (has_fifo_priority(a, b));
	else
		return (has_edf_priority(a, b));
}