/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 14:17:36 by camilla           #+#    #+#             */
/*   Updated: 2026/09/22 11:59:38 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	actions(t_coders *coders)
{
	pthread_mutex_lock(&coders->mutex);
	coders->n_of_compiles++;
	pthread_mutex_unlock(&coders->mutex);
	if (check_simulation(coders) != 0)
		return ;
	if (debug(coders) != 0)
		return ;
	if (check_simulation(coders) != 0)
		return ;
	if (refactor(coders) != 0)
		return ;
}

//  controlla che la dongle sx e dx siano accessibili in contemporanea
// t_available_dongle = tempo in millisecondi in cui la dongle sarà disponibile
// m_dongle = mutex che dice se la dongle è in uso o meno
// chiamata a boadcast per svegliare i thread in attesa di una dongle
int	compile(t_coders *cod) // finita per ora
{
	struct timeval	tv;
	long			time_save;

	if (if_dongle_is_available(cod) != 1)
	{
		take_dongle_message(cod);
		gettimeofday(&tv, NULL);
		time_save = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
		pthread_mutex_lock(&cod->mutex);
		cod->last_compile_start = time_save;
		pthread_mutex_unlock(&cod->mutex);
		compile_message(cod);
		usleep(cod->quantum->config.compile * 1000);
		gettimeofday(&tv, NULL);
		time_save = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
		cod->dongle_dx->t_available_dongle = (time_save
				+ cod->quantum->config.dongle_cooldown);
		cod->dongle_sx->t_available_dongle = (time_save
				+ cod->quantum->config.dongle_cooldown);
		mutex_unlock(cod);
		return (0);
	}
	return (1);
}

int	debug(t_coders *coders)
{
	debug_message(coders);
	usleep(coders->quantum->config.debug * 1000);
	return (0);
}

int	refactor(t_coders *coders)
{
	refactor_message(coders);
	usleep(coders->quantum->config.refactor * 1000);
	return (0);
}
