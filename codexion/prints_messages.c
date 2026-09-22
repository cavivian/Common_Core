/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_messages.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 12:04:03 by camilla           #+#    #+#             */
/*   Updated: 2026/09/22 10:03:32 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	compile_message(t_coders *coders)
{
	pthread_mutex_lock(&coders->quantum->m_print);
	printf("%ld %d is compiling\n", coders->last_compile_start
		- coders->quantum->simulation_start, coders->index);
	pthread_mutex_unlock(&coders->quantum->m_print);
}

void	debug_message(t_coders *coders)
{
	struct timeval	tv;
	long			save;

	gettimeofday(&tv, NULL);
	pthread_mutex_lock(&coders->quantum->m_print);
	save = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000))
		- coders->quantum->simulation_start;
	printf("%ld %d is debugging\n", save, coders->index);
	pthread_mutex_unlock(&coders->quantum->m_print);
}

void	refactor_message(t_coders *coders)
{
	struct timeval	tv;
	long			save;

	gettimeofday(&tv, NULL);
	pthread_mutex_lock(&coders->quantum->m_print);
	save = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000))
		- coders->quantum->simulation_start;
	printf("%ld %d is refactoring\n", save, coders->index);
	pthread_mutex_unlock(&coders->quantum->m_print);
}

void	take_dongle_message(t_coders *coders)
{
	struct timeval	tv;
	long			save;

	pthread_mutex_lock(&coders->quantum->m_print);
	gettimeofday(&tv, NULL);
	save = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000))
		- coders->quantum->simulation_start;
	printf("%ld %d has taken a dongle\n", save, coders->index);
	pthread_mutex_unlock(&coders->quantum->m_print);
	pthread_mutex_lock(&coders->quantum->m_print);
	gettimeofday(&tv, NULL);
	save = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000))
		- coders->quantum->simulation_start;
	printf("%ld %d has taken a dongle\n", save, coders->index);
	pthread_mutex_unlock(&coders->quantum->m_print);
}

void	burnout_message(t_coders *coders)
{
	struct timeval	tv;
	long			save;

	gettimeofday(&tv, NULL);
	pthread_mutex_lock(&coders->quantum->m_print);
	save = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000))
		- coders->quantum->simulation_start;
	printf("%ld %d burned out\n", save, coders->index);
	pthread_mutex_unlock(&coders->quantum->m_print);
}
