/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 11:18:30 by camilla           #+#    #+#             */
/*   Updated: 2026/09/16 23:01:52 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	has_fifo_priority(t_wait_node *a, t_wait_node *b)
{
	long	save_a;
	long	save_b;

	save_a = a->coder->quantum
}

int	has_edf_priority(t_wait_node *a, t_wait_node *b)
{
	long			save_a;
	long			save_b;

	save_a = a->coder->last_compile_start + a->coder->quantum->config.burnout;
	save_b = b->coder->last_compile_start + b->coder->quantum->config.burnout; // calcoli per la deadline di burnout
}


int	has_priority(t_wait_node *a, t_wait_node *b)
{
	if (a->coder->quantum->config.algorithm == FIFO)
		return (has_fifo_priority());
	else
		return (has_edf_priority(a, b));
}


void	*algorithm(t_check *check)
{
	struct timeval	tv;
	long			incoming_request;
	long			time_from_burnout;
	int				i;

	time_from_burnout = check->coders[i].last_compile_start + check->burnout;
	gettimeofday(&tv, NULL);
	incoming_request = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	if (check->coders->quantum->config.algorithm == FIFO)
	{
		
	}
	else if (check->coders->quantum->config.algorithm == EDF)
	{
		
	}
}