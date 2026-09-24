/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 09:24:02 by camilla           #+#    #+#             */
/*   Updated: 2026/09/24 18:42:11 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// funzione che controlla se ogni coder è in burnout
// "Da quando questo coder ha iniziato il suo ultimo compile, sono passati 
// almeno time_to_burnout millisecondi senza
// che abbia iniziato un altro compile?" - si
// da proteggere last compile
int	if_burnout(t_quantum *q, long save)
{
	int			i;
	int			burnout;

	i = 0;
	while (i < q->config.n_of_coders)
	{
		pthread_mutex_lock(&q->coders[i].mutex);
		burnout = save - q->coders[i].last_compile_start;
		pthread_mutex_unlock(&q->coders[i].mutex);
		if (burnout >= q->config.burnout)
		{
			pthread_mutex_lock(&q->m_simulation_stop);
			q->simulation_stop = 1;
			pthread_mutex_unlock(&q->m_simulation_stop);
			//printf("\nsto stampando il messaggio\n");
			burnout_message(&q->coders[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

void	monitor_centre(t_quantum *q)
{
	struct timeval	tv;
	long			save;

	//printf("\nsono dentro monitor_centre\n");
	gettimeofday(&tv, NULL);
	save = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	if (check_n_of_compiles(q) == 0)
	{
		//printf("\nsono dentro il controllo se check_n_of_compiles(check) == 0");
		simulation_stop_is_1(q);
	}
	if (if_burnout(q, save) != 0)
	{
		//printf("\nsono dentro il controllo del if_burnout quando fallisce\n");
	}
}

// decide se continuare o fermare la simulazione
void	*monitor(void *arg)
{
	t_quantum			*q;

	q = (t_quantum *)arg;
	//printf("\nsono dentro monitor");
	while (check_simulation(q->coders) == 0)
		monitor_centre(q);
	pthread_mutex_lock(&q->service_mutex);
	pthread_cond_broadcast(&q->service_condition);
	//printf("\n%d sto chiamando il broadcast\n", q->coders->index);
	pthread_mutex_unlock(&q->service_mutex);
	return (NULL);
}



int	init_check_monitor(t_quantum *q, t_coders *cod)
{
	if (pthread_create(&q->monitor_thread, NULL, monitor, q) != 0)
		return (1);
	(void)cod;
	return (0);
}
