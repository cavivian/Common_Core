/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:04 by cavivian          #+#    #+#             */
/*   Updated: 2026/09/30 12:47:55 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*routine(void *arg)
{
	t_coder	*coder;

	coder = (t_coder *)arg;
	if (coder->quantum->config.n_of_coders == 1)
		return (only_one_coder(coder), NULL);
	while (check_simulation(coder) == 0)
	{
		if (compile(coder) != 0)
		{
			usleep (1);
			continue ;
		}
		actions(coder);
	}
	return (NULL);
}

int	join_and_clean(t_quantum *q, int count, t_dongle *dongle)
{
	join_threads(q->coder, count);
	if (pthread_join(q->monitor_thread, NULL) != 0)
		return (1);
	cleanup_all(q->coder, q->config.n_of_coders);
	cleanup_dongle(dongle, count);
	pthread_mutex_destroy(&q->m_simulation_stop);
	pthread_mutex_destroy(&q->m_print);
	return (0);
}

int	only_one_coder(t_coder *coder)
{
	while(check_simulation(coder) == 0)
		usleep(1);
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
