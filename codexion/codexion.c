/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:04 by cavivian          #+#    #+#             */
/*   Updated: 2026/09/22 12:07:48 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*coderses(void *arg) // finita per adesso
{
	t_coders	*coders;
	int			i;

	i = 0;
	coders = (t_coders *)arg;
	while (i < coders->quantum->config.number_of_compiles_required)
	{
		if (check_simulation(coders) != 0)
			return (NULL);
		if (compile(coders) != 0)
		{
			usleep (10000);
			continue ;
		}
		actions(coders);
		i++;
	}
	return (NULL);
}

// 	t_coders *codx = malloc(sizeof(t_coders));
// Edo lo aveva scritto con un (coders[1] * sizeof(t_coders))
// parte del parse per controllare che i primi 7 arg siano int
// e che l'ultimo sia una stringa, controllo con strcmp
// questa funzione accetta che i primi 7 argomenti possano essere 0, sbagliato!
int	central_part(t_quantum *q, int count,
	t_check *check, t_dongle *dongle)
{
	if (init_check_monitor(check, q, q->coders) != 0)
	{
		join_threads(q->coders, count);
		cleanup_all(q->coders, q->config.n_of_coders);
		pthread_mutex_destroy(&q->m_simulation_stop);
		pthread_mutex_destroy(&q->m_print);
		pthread_mutex_destroy(&q->service_mutex);
		pthread_cond_destroy(&q->service_condition);
		cleanup(dongle, count);
		return (1);
	}
	join_threads(q->coders, count);
	if (pthread_join(q->monitor_thread, NULL) != 0)
		return (1);
	cleanup_all(q->coders, q->config.n_of_coders);
	cleanup(dongle, count);
	pthread_mutex_destroy(&q->m_simulation_stop);
	pthread_mutex_destroy(&q->m_print);
	pthread_mutex_destroy(&q->service_mutex);
	pthread_cond_destroy(&q->service_condition);
	return (0);
}

void	get_time(t_quantum *q)
{
	struct timeval	tv;

	q->simulation_stop = 0;
	gettimeofday(&tv, NULL);
	q->simulation_start = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	pthread_mutex_init(&q->m_simulation_stop, NULL);
	pthread_mutex_init(&q->m_print, NULL);
	pthread_mutex_init(&q->service_mutex, NULL);
	pthread_cond_init(&q->service_condition, NULL);
}

int	creation_arrays(t_coders **coders, t_quantum *q,
	t_dongle **dongle, int *count)
{
	*dongle = init_array_dongle(q);
	if (!*dongle)
		return (1);
	*coders = init_array_coders(q, count, *dongle);
	if (!*coders)
		return (1);
	q->coders = *coders;
	q->wait_heap = init_array_heap(q->config.n_of_coders);
	if (!q->wait_heap)
		return (1);
	return (0);
}

//qua dentro ci  stanno le chiamate alle funzioni. prima parse
// poi creazione thread, e la creazione dell'array preso dal parse
// se il parse fallisce il programma deve terminare
int	main(int argc, char *argv[])
{
	t_quantum		q;
	t_check			check;
	int				count;
	t_dongle		*dongle;
	t_coders		*coders;

	count = 0;
	if (argc != 9)
		return (0);
	memset(&check, 0, sizeof(t_check));
	if (validation(argc, argv) == 0)
	{
		if (parse(&q, argc, argv) == 0)
		{
			get_time(&q);
			if (creation_arrays(&coders, &q, &dongle, &count) != 0)
				return (1);
			if (central_part(&q, count, &check, dongle) != 0)
				return (1);
		}
		return (0);
	}
	return (1);
}
