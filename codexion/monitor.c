/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 09:24:02 by camilla           #+#    #+#             */
/*   Updated: 2026/09/30 12:06:26 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	if_burnout(t_quantum *q, long save)
{
	int			i;
	int			burnout;

	i = 0;
	while (i < q->config.n_of_coders)
	{
		pthread_mutex_lock(&q->coder[i].mutex);
		burnout = save - q->coder[i].last_compile_start;
		pthread_mutex_unlock(&q->coder[i].mutex);
		if (burnout >= q->config.burnout)
		{
			pthread_mutex_lock(&q->m_simulation_stop);
			q->simulation_stop = 1;
			pthread_mutex_unlock(&q->m_simulation_stop);
			burnout_message(&q->coder[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

void	monitor_centre(t_quantum *q)
{
	long			save;

	save = get_time();
	if (check_n_of_compiles(q) == 0)
		simulation_stop_is_1(q);
	if (if_burnout(q, save) != 0)
		return ;
}

void	*monitor(void *arg)
{
	t_quantum			*q;

	q = (t_quantum *)arg;
	while (check_simulation(q->coder) == 0)
	{
		monitor_centre(q);
		usleep(1);
	}
	pthread_mutex_lock(&q->service_mutex);
	pthread_cond_broadcast(&q->service_condition);
	pthread_mutex_unlock(&q->service_mutex);
	return (NULL);
}

int	init_check_monitor(t_quantum *q)
{
	if (pthread_create(&q->monitor_thread, NULL, monitor, q) != 0)
		return (1);
	return (0);
}
