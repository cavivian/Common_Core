/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 11:18:30 by camilla           #+#    #+#             */
/*   Updated: 2026/09/16 14:10:18 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"


int	has_priority(t_wait_node *a, t_wait_node *b)
{
	long			save_a;
	long			save_b;

	save_a = a->coder->last_compile_start + a->coder->quantum->config.burnout;
	save_b = b->coder->last_compile_start + b->coder->quantum->config.burnout; // calcoli per la deadline di burnout
	if (save_a < save_b)
		return (1);
	else
		return (0);
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