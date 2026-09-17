/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 09:24:02 by camilla           #+#    #+#             */
/*   Updated: 2026/09/17 17:22:22 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// funzione che controlla se ogni coder è in burnout
int	if_burnout(t_check *check, long save) // finita
{
	int			i; // indice per visitare un coder alla volta
	int			burnout;

	i = 0;
	while(i < check->n_of_coders)
	{
		// "Da quando questo coder ha iniziato il suo ultimo compile, sono passati 
		// almeno time_to_burnout millisecondi senza che abbia iniziato un altro compile?" - si
		// da proteggere last compile
		pthread_mutex_lock(&check->coders[i].mutex);
		burnout = save - check->coders[i].last_compile_start;
		pthread_mutex_unlock(&check->coders[i].mutex);
		if (burnout >= *check->burnout)
		{
			pthread_mutex_lock(check->m_simulation_stop);
			*check->simulation_stop = 1; // stoppa la simulazione
			pthread_mutex_unlock(check->m_simulation_stop);
			burnout_message(&check->coders[i]);
			return(1);
		}
		i++;
	}
	return (0);
}


void	monitor_centre(t_check *check, int *check_simulation)
{
	struct timeval	tv;
	long	save;

	pthread_mutex_lock(check->m_simulation_stop);
	*check_simulation = *check->simulation_stop;
	pthread_mutex_unlock(check->m_simulation_stop);
	if (*check_simulation != 0)
		return ;
	gettimeofday(&tv, NULL);
	save = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	if (check_n_of_compiles(check) == 0)
	{
		simulation_stop_is_1(check);
		*check_simulation = 1;
	}
	if (if_burnout(check, save) != 0)
		*check_simulation = 1;
}

// decide se continuare o fermare la simulazione
void	*monitor(void *arg)
{
	t_check			*check = (t_check*)arg;
	int				check_simulation;

	check_simulation = 0;
	while(check_simulation == 0)
		monitor_centre(check, &check_simulation);
	pthread_mutex_lock(check->service_mutex);
	pthread_cond_broadcast(check->service_condition);
	pthread_mutex_unlock(check->service_mutex);
	return (NULL);
}

int	init_check_monitor(t_check *check, t_quantum *q, t_coders *cod) // finita
{
	check->number_of_compiles_required = &q->config.number_of_compiles_required;
	check->burnout = &q->config.burnout;
	check->dongle_cooldown = &q->config.dongle_cooldown;
	check->n_of_coders = q->config.n_of_coders;
	check->coders = cod;
	check->simulation_stop = &q->simulation_stop;
	check->m_simulation_stop = &q->m_simulation_stop;
	check->service_condition = &q->service_condition;
	check->service_mutex = &q->service_mutex;
	if(pthread_create(&q->monitor_thread, NULL, monitor, check) != 0)
		return (1);
	return (0);
}