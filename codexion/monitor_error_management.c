/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_error_management.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:49:40 by camilla           #+#    #+#             */
/*   Updated: 2026/09/30 12:47:41 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	check_n_of_compiles(t_quantum *q)
{
	int	i;
	int	check_of_compile;

	i = 0;
	while (i < q->config.n_of_coders)
	{
		pthread_mutex_lock(&q->coder[i].mutex);
		check_of_compile = q->coder[i].n_of_compiles;
		pthread_mutex_unlock(&q->coder[i].mutex);
		if (check_of_compile < q->config.number_of_compiles_required)
			return (1);
		i++;
	}
	return (0);
}

int	monitor_errors(t_quantum *q)
{
	cleanup_all(q->coder, q->config.n_of_coders);
	pthread_mutex_destroy(&q->m_simulation_stop);
	pthread_mutex_destroy(&q->m_print);
	return (1);
}
