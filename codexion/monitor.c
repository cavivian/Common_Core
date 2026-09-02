/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 09:24:02 by camilla           #+#    #+#             */
/*   Updated: 2026/09/02 10:51:08 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"


// funzione che controlla se ogni coder è in burnout
void	if_burnout(t_check *check, long save)
{
	int	i; // indice per visitare un coder alla volta

	i = 0;
	while(i < check->n_of_coders)
	{
		// "Da quando questo coder ha iniziato il suo ultimo compile, sono passati 
		// almeno time_to_burnout millisecondi senza che abbia iniziato un altro compile?" - si
		if (save - check->coders[i].last_compile_start >= *check->burnout)
		{
			pthread_mutex_lock(check->m_simulation_stop);
			*check->simulation_stop = 1;
			pthread_mutex_unlock(check->m_simulation_stop);
		}
		i++;
	}
}

void	*monitor(void *arg)
{
	t_check	*check = (t_check*)arg;
	struct timeval	tv;
	long	save;

	while(*check->simulation_stop == 0)
	{
		gettimeofday(&tv, NULL);
		save = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
		if_burnout(check, save);
	}
	return (NULL);
}

int	init_check_monitor(t_check *check, t_quantum *q, t_coders *cod)
{
	check->number_of_compiles_required = &q->config.number_of_compiles_required;
	check->burnout = &q->config.burnout;
	check->dongle_cooldown = &q->config.dongle_cooldown;
	check->n_of_coders = q->config.n_of_coders;
	check->coders = cod;
	check->simulation_stop = &q->simulation_stop;
	check->m_simulation_stop = &q->m_simulation_stop;
	if(pthread_create(&q->monitor_thread, NULL, monitor, check) != 0)
	{
		
	}
}