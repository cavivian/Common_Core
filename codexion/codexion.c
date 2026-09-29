/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:04 by cavivian          #+#    #+#             */
/*   Updated: 2026/09/29 22:14:06 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// funzione che da il via alle azioni
void	*routine(void *arg)
{
	t_coder	*coder;
	int		i;

	i = 0;
	coder = (t_coder *)arg;
	if (coder->quantum->config.n_of_coders == 1)
		return (only_one_coder(coder), NULL);
	while (i < coder->quantum->config.number_of_compiles_required)
	{
		if (check_simulation(coder) != 0)
			return (NULL);
		if (compile(coder) != 0)
		{
			usleep (1);
			continue ;
		}
		actions(coder);
		i++;
	}
	return (NULL);
}

// join di tutti i thread creati
int	join_and_clean(t_quantum *q, int count, t_dongle *dongle)
{
	join_threads(q->coder, count);
	if (pthread_join(q->monitor_thread, NULL) != 0)
		return (1);
	cleanup_all(q->coder, q->config.n_of_coders);
	cleanup_dongle(dongle, count);
	pthread_mutex_destroy(&q->m_simulation_stop);
	pthread_mutex_destroy(&q->m_print);
	pthread_mutex_destroy(&q->service_mutex);
	pthread_cond_destroy(&q->service_condition);
	return (0);
}

// comportamento per un solo coder
int	only_one_coder(t_coder *coder)
{
	if (check_simulation(coder) == 0)
	{
		pthread_mutex_lock(&coder->quantum->m_simulation_stop);
		usleep(coder->quantum->config.burnout * 1000);
		pthread_mutex_unlock(&coder->quantum->m_simulation_stop);
		return (1);
	}
	return (0);
}

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
	if (creation_arrays(&q, &dongle) != 0)
		return (1);
	if (handle_coders_thread(q.coder, q.config.n_of_coders,
			dongle, &count) != 0)
		return (1);
	init_monitor_threads(&q);
	if (join_and_clean(&q, count, dongle) != 0)
		return (1);
	return (0);
}
