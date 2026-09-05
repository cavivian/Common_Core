/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 14:17:36 by camilla           #+#    #+#             */
/*   Updated: 2026/09/03 12:17:16 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

int	compile(t_coders *cod) // finita per ora
{
	struct timeval	tv;
	long			time_save;
	
	if (if_dongle_is_available(cod) == 1) // controlla che la dongle sx e dx siano accessibili in contemporanea
	{
		gettimeofday(&tv, NULL);
		time_save = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
		cod->n_of_compiles++;
		cod->last_compile_start = time_save;
		usleep(cod->quantum->config.compile * 1000);
		gettimeofday(&tv, NULL);
		time_save = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
		cod->dongle_dx->t_available_dongle = time_save + cod->quantum->config.dongle_cooldown;
		cod->dongle_sx->t_available_dongle = time_save + cod->quantum->config.dongle_cooldown;
		pthread_mutex_unlock(&cod->dongle_dx->m_dongle);
		pthread_mutex_unlock(&cod->dongle_sx->m_dongle);
		return (1);
	}
	return (0);
}