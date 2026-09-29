/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 21:54:29 by camilla           #+#    #+#             */
/*   Updated: 2026/09/29 13:52:00 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// inizio della simulazione e identificazione del momento attuale
void	init_simulation_and_mutex(t_quantum *q)
{
	q->simulation_stop = 0;
	q->simulation_start = get_time();
	pthread_mutex_init(&q->m_simulation_stop, NULL);
	pthread_mutex_init(&q->m_print, NULL);
	pthread_mutex_init(&q->service_mutex, NULL);
	pthread_cond_init(&q->service_condition, NULL);
}

// 
void	lock_unlock_of_mutex(t_coder *coder)
{
	pthread_mutex_lock(&coder->dongle_sx->m_dongle);
	pthread_mutex_lock(&coder->dongle_dx->m_dongle);
	pthread_mutex_unlock(&coder->quantum->service_mutex);
}

// controlla se la simulazione è finita o no.
int	check_simulation(t_coder *coder)
{
	pthread_mutex_lock(&coder->quantum->m_simulation_stop);
	if (coder->quantum->simulation_stop == 1)
	{
		pthread_mutex_unlock(&coder->quantum->m_simulation_stop);
		return (1);
	}
	pthread_mutex_unlock(&coder->quantum->m_simulation_stop);
	return (0);
}

// imposta il simulation stop a 1
void	simulation_stop_is_1(t_quantum *q)
{
	pthread_mutex_lock(&q->m_simulation_stop);
	q->simulation_stop = 1;
	pthread_mutex_unlock(&q->m_simulation_stop);
}
