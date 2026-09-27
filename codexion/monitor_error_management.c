/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_error_management.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:49:40 by camilla           #+#    #+#             */
/*   Updated: 2026/09/27 19:18:29 by camilla          ###   ########.fr       */
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

// gestisce la distruzione dei mutex e il free in caso di errore di creazione del thread del monitor
int	monitor_errors(t_quantum *q)
{
	cleanup_all(q->coders, q->config.n_of_coders);
	pthread_mutex_destroy(&q->m_simulation_stop);
	pthread_mutex_destroy(&q->m_print);
	pthread_mutex_destroy(&q->service_mutex);
	pthread_cond_destroy(&q->service_condition);
	return (1);
}