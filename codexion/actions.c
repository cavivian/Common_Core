/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 14:17:36 by camilla           #+#    #+#             */
/*   Updated: 2026/09/27 22:16:06 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// ultima parte di coderses
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

// controlla che la dongle sx e dx siano accessibili in contemporanea
// t_available_dongle = tempo in millisecondi in cui la dongle sarà disponibile
// m_dongle = mutex che dice se la dongle è in uso o meno
// chiamata a boadcast per svegliare i thread in attesa di una dongle
int	compile(t_coders *cod)
{
	long			time_save;

	register_heap(cod);
	while (check_simulation(cod) != 1)
		if (if_dongle_is_available(cod) != 1)
			break ;
	take_dongle_message(cod);
	time_save = get_time();
	pthread_mutex_lock(&cod->mutex);
	cod->last_compile_start = time_save;
	pthread_mutex_unlock(&cod->mutex);
	compile_message(cod);
	usleep(cod->quantum->config.compile * 1000);
	time_save = get_time();
	pthread_mutex_lock(&cod->dongle_dx->m_dongle);
	cod->dongle_dx->t_available_dongle = (time_save
		+ cod->quantum->config.dongle_cooldown);
	cod->dongle_dx->is_not_available = 0;
	pthread_mutex_unlock(&cod->dongle_dx->m_dongle);
	pthread_mutex_lock(&cod->dongle_sx->m_dongle);
	cod->dongle_sx->t_available_dongle = (time_save
		+ cod->quantum->config.dongle_cooldown);
	cod->dongle_sx->is_not_available = 0;
	return (pthread_mutex_unlock(&cod->dongle_sx->m_dongle), 0);
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
