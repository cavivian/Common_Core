/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 09:36:04 by camilla           #+#    #+#             */
/*   Updated: 2026/09/25 13:22:55 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// devo gestire quando il coder è uno solo, ma lo gestisco in un'altra funzione
t_coders	*give_dongle(t_coders *cod, t_dongle *dongle, int size)
{
	int	i;

	i = 0;
//	printf("\nsto assegnando le dongle\n");
	while (i < size)
	{
		cod[i].dongle_sx = &dongle[i];
		cod[i].dongle_dx = &dongle[(i + 1) % cod->quantum->config.n_of_coders];
		if (i == 0)
		{
			cod[i].dongle_sx = cod[i].dongle_dx;
			cod[i].dongle_dx = &dongle[i];
		}
		i++;
	}
	return (cod);
}

long	get_eta_cooldown_time(t_dongle *dongle)
{
	long	available;

	available = 0;
	pthread_mutex_lock(&dongle->m_dongle);
	available = dongle->t_available_dongle;
	pthread_mutex_unlock(&dongle->m_dongle);
	return (available);
}

int	centre(t_coders *coders, long actually_time, struct timespec *ts)
{
	struct timeval	tv;
	(void)ts;
	//printf("\n%d sono dentro centre\n", coders->index);
	printf("\nstatus di simulation stop: %d\n", coders->quantum->simulation_stop);
	while (get_eta_cooldown_time(coders->dongle_sx) >= actually_time
		|| (get_eta_cooldown_time(coders->dongle_dx) >= actually_time)
		|| coders->quantum->wait_heap.array[0].coder != coders)
	{
	//	printf("%d ", actually_time);
		gettimeofday(&tv, NULL);
		actually_time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
		if (check_simulation(coders) != 0)
		{
		//	printf("\n%d sono entrato dentro il timedwait\n", coders->index);
			printf("\nstatus di simulation stop: %d\n", coders->quantum->simulation_stop);
			pthread_mutex_unlock(&coders->quantum->service_mutex);
			return (1);
		}
		//printf("\n%d sono fuori dal timedwait\n", coders->index);
	}
	return (0);
}

void	lock_unlock_of_mutex(t_coders *coders)
{
	pthread_mutex_lock(&coders->dongle_sx->m_dongle);
	pthread_mutex_lock(&coders->dongle_dx->m_dongle);
	pthread_mutex_unlock(&coders->quantum->service_mutex);
}

void	apply_cooldown(t_coders *coder)
{
	struct timeval tv;
	long time_dx;
	long time_sx;
	long actual_time;

	gettimeofday(&tv, NULL);
	actual_time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	time_dx = get_eta_cooldown_time(coder->dongle_dx) - actual_time;
	time_sx = get_eta_cooldown_time(coder->dongle_sx) - actual_time;
	actual_time = time_dx;
	if (time_sx > actual_time)
		actual_time = time_sx;
	if (actual_time <= 0)
		return ;
	usleep(actual_time * 1000);
}

// controlla se è possibile prendere due dongle in contemporanea
// manca caso un solo coder
// t_available_dongle in get_eta_cooldown_time
// è un punto preciso, non è una durata
// save mi dice per quanto tempo posso stare
// nel ciclo prima di raggiungere il burnout

int	if_dongle_is_available(t_coders *coder)
{
	int	dongle_dx;
	int	dongle_sx;

	pthread_mutex_lock(&coder->dongle_dx->m_dongle);
	dongle_dx = coder->dongle_dx->is_not_available == 0
		&& coder->dongle_dx->heap.array[0].coder == coder;
	pthread_mutex_lock(&coder->dongle_sx->m_dongle);
	dongle_sx = coder->dongle_sx->is_not_available == 0
		&& coder->dongle_sx->heap.array[0].coder == coder;
	if (dongle_dx && dongle_sx)
	{
		coder->dongle_dx->is_not_available = 1;
		coder->dongle_sx->is_not_available = 1;
		
		pthread_mutex_unlock(&coder->dongle_sx->m_dongle);
		pthread_mutex_unlock(&coder->dongle_dx->m_dongle);
		return (0);
	}
	pthread_mutex_unlock(&coder->dongle_sx->m_dongle);
	pthread_mutex_unlock(&coder->dongle_dx->m_dongle);
	return (1);
}








// int	if_dongle_is_available(t_coders *coders)
// {
// 	struct timespec	ts;
// 	struct timeval	tv;
// 	long			save;
// 	long			actually_time;
// 	long			timestamp_for_value;
// 	t_wait_node		node;

// 	save = (coders->last_compile_start + coders->quantum->config.burnout);
// 	ts.tv_sec = save / 1000;
// 	ts.tv_nsec = (save % 1000) * 1000000;
// 	gettimeofday(&tv, NULL);
// 	timestamp_for_value = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
// 	pthread_mutex_lock(&coders->quantum->service_mutex);
// 	gettimeofday(&tv, NULL);
// 	actually_time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
// 	node = create_wait_node(coders, coders->quantum->config.algorithm,
// 		timestamp_for_value);
// 	push_into_the_heap(&coders->quantum->wait_heap, &node);
// 	if (centre(coders, actually_time, &ts) != 0)
// 		return (1);
// 	//printf("\n%d sono fuori da centre", coders->index);
// 	delete_max_priority_node(&coders->quantum->wait_heap, &node);
// 	lock_unlock_of_mutex(coders);
// 	return (0);
// }

// utilizzo di pthread_cond_timedwait()e pthread_cond_wait():
// permettono di addormentare un thread finchè una 
// certa condizione non si verifica senza consumare CPU
// e di essere risvegliato dall'OS quando quel qualcosa accade
// (grazie a broadcast/signal, fatti da un'altro thread)
// cond_wait fa il rilascio del mutex e l'addormentamento del thread
// in un unico passaggio, perchè potrebbe succedere che tra un 
// passaggio e l'altro un altro thread faccia il suo broadcast,
// e quello addormentato rimanga così per sempre. è per maggiore sicurezza
// ma la differenza con timedwait sta nel fatto che quest'ultimo
// lo fa con un'uscita di sicurezza: ovvero se arriva all'istante
// assoluto della deadline, fa risvegliare il thread,
// e la funzione ritorna un messaggio di default di errore.
// pthread_cond_wait invece aspetterebbe per sempre