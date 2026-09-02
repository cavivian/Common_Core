/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 09:36:04 by camilla           #+#    #+#             */
/*   Updated: 2026/09/02 17:34:39 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

t_coders	*give_dongle(t_coders *cod, t_dongle *dongle, int size)
{
	int	i;

	i = 0;
	if (size == 1) // se abbiamo un solo coder, abbiamo anche una sola dongle
	{
		cod[i].dongle_dx = &dongle[0];
		cod[i].dongle_sx = &dongle[0];
	}
	else
	{
		while (i < size)
		{
			if (i == 0) // se e' il primo coder
			{
				cod[i].dongle_sx = &dongle[size - 1];
				cod[i].dongle_dx = &dongle[i + 1];
			}
			else
			{
				if (i == size - 1)
				{
					cod[i].dongle_dx = &dongle[0];
					cod[i].dongle_sx = &dongle[i];
				}
				else
				{
					cod[i].dongle_dx = &dongle[i + 1];
					cod[i].dongle_sx = &dongle[i];	
				}
			}
			i++;
		}
	}
	return (cod);
}

// controlla se è possibile prendere due dongle in contemporanea
int	if_dongle_is_available(t_coders *coders) // finita
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	while(((tv.tv_sec * 1000) + (tv.tv_usec / 1000)) <
	(coders->last_compile_start + coders->quantum->config.burnout))
	{
		gettimeofday(&tv, NULL);
		if(pthread_mutex_trylock(&coders->dongle_dx->m_dongle) != 0)
			continue;
		if (pthread_mutex_trylock(&coders->dongle_sx->m_dongle) != 0)
		{
			pthread_mutex_unlock(&coders->dongle_dx->m_dongle);
			continue;
		}
		return (1);
	}
	return (0);
}