/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:04 by cavivian          #+#    #+#             */
/*   Updated: 2026/09/25 17:46:21 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*coderses(void *arg)
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
			usleep (1);
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
int	central_part(t_quantum *q, int count, t_dongle *dongle)
{
	join_threads(q->coders, count);
	cleanup_all(q->coders, q->config.n_of_coders);
	cleanup(dongle, count);
	pthread_mutex_destroy(&q->m_simulation_stop);
	pthread_mutex_destroy(&q->m_print);
	pthread_mutex_destroy(&q->service_mutex);
	pthread_cond_destroy(&q->service_condition);
	return (0);
}

void	init_simulation_and_mutex(t_quantum *q)
{
	q->simulation_stop = 0;
	q->simulation_start = get_time();
	pthread_mutex_init(&q->m_simulation_stop, NULL);
	pthread_mutex_init(&q->m_print, NULL);
	pthread_mutex_init(&q->service_mutex, NULL);
	pthread_cond_init(&q->service_condition, NULL);
}

int	creation_arrays(t_coders **coders, t_quantum *q,
	t_dongle **dongle)
{
	*dongle = init_array_dongle(q);
	if (!*dongle)
		return (1);
	// q->wait_heap = init_array_heap(q->config.n_of_coders);
	// if (!q->wait_heap.array)
	// 	return (1);
	q->coders = init_array_coders(q, *dongle);
	if (!q->coders)
		return (1);
	(void)coders;
	return (0);
}

/**
 * VALIDATION
 * PARSING > valorizza quantum.config
 * INIT DEI DATI[QUANTUM(MUTEX, START DATE), CODERS, DONGLES] con protezione di failure
 * CREAZIONE THREAD[CODERS, MONITOR]
 *  ... vita coder
 * JOIN MONITOR
 * JOIN CODER
 * EXIT
 */

int	main(int argc, char *argv[])
{
	t_quantum		q;
	int				count;
	t_dongle		*dongle;

	count = 0;
	if (argc != 9)
		return (1);
	memset(&q, 0, sizeof(t_quantum));
	if (validation(argc, argv) != 0)
		return (1);
	if (parse(&q, argc, argv) != 0)
		return (1);
	init_simulation_and_mutex(&q);
	if (creation_arrays(&q.coders, &q, &dongle) != 0)
		return (1);
	if (handle_coders_thread(q.coders, q.config.n_of_coders, dongle, &count) != 0)
		return (1);
	init_monitor_threads(&q);
	if (central_part(&q, count, dongle) != 0)
		return (1);
	return (1);
}
