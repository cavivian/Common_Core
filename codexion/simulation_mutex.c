/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 21:54:29 by camilla           #+#    #+#             */
/*   Updated: 2026/09/25 21:58:07 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	init_simulation_and_mutex(t_quantum *q)
{
	q->simulation_stop = 0;
	q->simulation_start = get_time();
	pthread_mutex_init(&q->m_simulation_stop, NULL);
	pthread_mutex_init(&q->m_print, NULL);
	pthread_mutex_init(&q->service_mutex, NULL);
	pthread_cond_init(&q->service_condition, NULL);
}

void	lock_unlock_of_mutex(t_coders *coders)
{
	pthread_mutex_lock(&coders->dongle_sx->m_dongle);
	pthread_mutex_lock(&coders->dongle_dx->m_dongle);
	pthread_mutex_unlock(&coders->quantum->service_mutex);
}

// controlla se la simulazione è finita o no.
int	check_simulation(t_coders *coders)
{
	pthread_mutex_lock(&coders->quantum->m_simulation_stop);
	//printf("\nstatus di simulation stop dentro check_simulation: %d", coders->quantum->simulation_stop);
	if (coders->quantum->simulation_stop == 1)
	{
	//	printf("\nsono dentro\n");
		
		//printf("\nsono dentro check_simulation");
		pthread_mutex_unlock(&coders->quantum->m_simulation_stop);
		return (1);
	}
	pthread_mutex_unlock(&coders->quantum->m_simulation_stop);
	return (0);
}

// imposta il simulation stop a 1
void	simulation_stop_is_1(t_quantum *q)
{
	pthread_mutex_lock(&q->m_simulation_stop);
	q->simulation_stop = 1;
	pthread_mutex_unlock(&q->m_simulation_stop);
}