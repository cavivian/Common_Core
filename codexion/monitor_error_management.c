/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_error_management.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:49:40 by camilla           #+#    #+#             */
/*   Updated: 2026/09/25 17:48:28 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// controlla che tutti i coder abbiano completato i compile richiesti
int	check_n_of_compiles(t_quantum *q)
{
	int	i;
	int	check_of_compile;

	i = 0;
	while (i < q->config.n_of_coders)
	{
		pthread_mutex_lock(&q->coders[i].mutex);
		check_of_compile = q->coders[i].n_of_compiles;
		pthread_mutex_unlock(&q->coders[i].mutex);
		if (check_of_compile < q->config.number_of_compiles_required)
			return (1);
		i++;
	}
	return (0);
}

// imposta il simulation stop a 1
void	simulation_stop_is_1(t_quantum *q)
{
	pthread_mutex_lock(&q->m_simulation_stop);
	q->simulation_stop = 1;
	pthread_mutex_unlock(&q->m_simulation_stop);
}

int	monitor_errors(t_quantum *q)
{
	cleanup_all(q->coders, q->config.n_of_coders);
	pthread_mutex_destroy(&q->m_simulation_stop);
	pthread_mutex_destroy(&q->m_print);
	pthread_mutex_destroy(&q->service_mutex);
	pthread_cond_destroy(&q->service_condition);
	return (1);
}