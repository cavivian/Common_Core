/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_messages.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 12:04:03 by camilla           #+#    #+#             */
/*   Updated: 2026/09/09 22:44:09 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	compile_message(t_coders *coders)
{
	pthread_mutex_lock(&coders->quantum->m_print);
	printf("%ld %d is compiling\n", coders->last_compile_start - 
		coders->quantum->simulation_start, coders->index);
	pthread_mutex_unlock(&coders->quantum->m_print);
}


void	debug_message(t_coders *coders)
{
	struct timeval	tv;
	long			save;
	gettimeofday(&tv, NULL);
	
	save = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000))
	- coders->quantum->simulation_start;
	pthread_mutex_lock(&coders->quantum->m_print);
	printf("%ld %d is debugging\n", save, coders->index);
	pthread_mutex_unlock(&coders->quantum->m_print);
}


void	refactor_message(t_coders *coders)
{
	struct timeval	tv;
	long			save;
	gettimeofday(&tv, NULL);

	save = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000))
	- coders->quantum->simulation_start;
	pthread_mutex_lock(&coders->quantum->m_print);
	printf("%ld %d is refactoring\n", save, coders->index);
	pthread_mutex_unlock(&coders->quantum->m_print);
}


void	take_dongle_message(t_coders *coders)
{
	struct timeval	tv;
	long			save;
	gettimeofday(&tv, NULL);

	save = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000))
	- coders->quantum->simulation_start;
	pthread_mutex_lock(&coders->quantum->m_print);
	printf("%ld %d has taken a dongle\n", save, coders->index);
	pthread_mutex_unlock(&coders->quantum->m_print);
}

void	burnout_message(t_coders *coders)
{
	struct timeval	tv;
	long			save;
	gettimeofday(&tv, NULL);

	save = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000))
	- coders->quantum->simulation_start;
	pthread_mutex_lock(&coders->quantum->m_print);
	printf("%ld %d burned out\n", save, coders->index);
	pthread_mutex_unlock(&coders->quantum->m_print);
}