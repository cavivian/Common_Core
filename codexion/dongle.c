/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 09:36:04 by camilla           #+#    #+#             */
/*   Updated: 2026/09/11 17:50:32 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// devo gestire quando il coder è uno solo, ma lo gestisco in un'altra funzione
t_coders	*give_dongle(t_coders *cod, t_dongle *dongle, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		//if_dongle_is_available(cod);
		//pthread_mutex_lock(&dongle->m_dongle);
		cod[i].dongle_sx = &dongle[i];
		cod[i].dongle_dx = &dongle[(i + 1) % cod->quantum->config.n_of_coders];
		//pthread_mutex_unlock(&dongle->m_dongle);
		i++;
	}
	return (cod);
}


long	check_available_dongle(t_dongle *dongle)
{
	long	available;

	available = 0;
	pthread_mutex_lock(&dongle->m_dongle);
	available = dongle->t_available_dongle;
	pthread_mutex_unlock(&dongle->m_dongle);
	return (available);
}


// controlla se è possibile prendere due dongle in contemporanea
// qui manca la chiamata a FIFO e EDF
// manca caso un solo coder
// non si possono usare i trylock
int	if_dongle_is_available(t_coders *coders) 
{
	struct timeval		tv;
	long				available_dx;
	long				available_sx;

	gettimeofday(&tv, NULL);
	while(((tv.tv_sec * 1000) + (tv.tv_usec / 1000)) <
	(coders->last_compile_start + coders->quantum->config.burnout))
	{
		available_dx = check_available_dongle(coders->dongle_dx);
		available_sx = check_available_dongle(coders->dongle_sx);
		gettimeofday(&tv, NULL);
		if (((tv.tv_sec * 1000) + (tv.tv_usec / 1000)) < available_dx)
			continue;
		if (((tv.tv_sec * 1000) + (tv.tv_usec / 1000)) < available_sx)
			continue;
		if (pthread_mutex_trylock(&coders->dongle_dx->m_dongle) != 0)
			continue;
		if (pthread_mutex_trylock(&coders->dongle_sx->m_dongle) != 0)
		{
			pthread_mutex_unlock(&coders->dongle_dx->m_dongle);
			continue;
		}
		return (0);
	}
	return (1);
}
