/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 09:36:04 by camilla           #+#    #+#             */
/*   Updated: 2026/09/30 15:50:32 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

t_coder	*give_dongle(t_coder *cod, t_dongle *dongle, int size)
{
	int	i;

	i = 0;
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

void	apply_cooldown(t_coder *coder)
{
	long	time_dx;
	long	time_sx;
	long	actual_time;

	actual_time = get_time();
	time_dx = get_eta_cooldown_time(coder->dongle_dx) - actual_time;
	time_sx = get_eta_cooldown_time(coder->dongle_sx) - actual_time;
	actual_time = time_dx;
	if (time_sx > actual_time)
		actual_time = time_sx;
	if (actual_time <= 0)
		return ;
	usleep(actual_time * 1000);
}

int	if_dongle_is_available(t_coder *coder)
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
		delete_max_priority_node(&coder->dongle_dx->heap);
		delete_max_priority_node(&coder->dongle_sx->heap);
		pthread_mutex_unlock(&coder->dongle_sx->m_dongle);
		pthread_mutex_unlock(&coder->dongle_dx->m_dongle);
		apply_cooldown(coder);
		return (0);
	}
	pthread_mutex_unlock(&coder->dongle_sx->m_dongle);
	pthread_mutex_unlock(&coder->dongle_dx->m_dongle);
	return (1);
}
