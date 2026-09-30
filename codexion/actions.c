/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 14:17:36 by camilla           #+#    #+#             */
/*   Updated: 2026/09/30 12:07:24 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	actions(t_coder *coder)
{
	pthread_mutex_lock(&coder->mutex);
	coder->n_of_compiles++;
	pthread_mutex_unlock(&coder->mutex);
	if (check_simulation(coder) != 0)
		return ;
	if (debug(coder) != 0)
		return ;
	if (check_simulation(coder) != 0)
		return ;
	if (refactor(coder) != 0)
		return ;
}

void	freedom_dongle(t_dongle *dongle, pthread_mutex_t *m_dongle,
	long time_save)
{
	pthread_mutex_lock(m_dongle);
	dongle->t_available_dongle = time_save;
	dongle->is_not_available = 0;
	pthread_mutex_unlock(m_dongle);
}

int	compile(t_coder *cod)
{
	long			time_save;

	register_heap(cod);
	while (check_simulation(cod) == 0)
	{
		if (if_dongle_is_available(cod) != 1)
			break ;
		usleep(1);
	}
	take_dongle_message(cod);
	time_save = get_time();
	pthread_mutex_lock(&cod->mutex);
	cod->last_compile_start = time_save;
	pthread_mutex_unlock(&cod->mutex);
	compile_message(cod);
	pthread_mutex_lock(&cod->mutex);
	usleep(cod->quantum->config.compile * 1000);
	pthread_mutex_unlock(&cod->mutex);
	time_save = get_time();
	freedom_dongle(cod->dongle_dx, &cod->dongle_dx->m_dongle, time_save
		+ cod->quantum->config.dongle_cooldown);
	freedom_dongle(cod->dongle_sx, &cod->dongle_sx->m_dongle, time_save
		+ cod->quantum->config.dongle_cooldown);
	return (0);
}

int	debug(t_coder *coder)
{
	debug_message(coder);
	usleep(coder->quantum->config.debug * 1000);
	return (0);
}

int	refactor(t_coder *coder)
{
	refactor_message(coder);
	usleep(coder->quantum->config.refactor * 1000);
	return (0);
}
