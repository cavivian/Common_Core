/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_messages.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 12:04:03 by camilla           #+#    #+#             */
/*   Updated: 2026/09/25 17:37:56 by cavivian         ###   ########.fr       */
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
	long			save;

	pthread_mutex_lock(&coders->quantum->m_print);
	save = get_time() - coders->quantum->simulation_start;
	printf("%ld %d is debugging\n", save, coders->index);
	pthread_mutex_unlock(&coders->quantum->m_print);
}

void	refactor_message(t_coders *coders)
{
	long			save;

	pthread_mutex_lock(&coders->quantum->m_print);
	save = get_time() - coders->quantum->simulation_start;
	printf("%ld %d is refactoring\n", save, coders->index);
	pthread_mutex_unlock(&coders->quantum->m_print);
}

void	take_dongle_message(t_coders *coders)
{
	long			save;

	pthread_mutex_lock(&coders->quantum->m_print);
	save = get_time() - coders->quantum->simulation_start;
	printf("%ld %d has taken a dongle\n", save, coders->index);
	pthread_mutex_unlock(&coders->quantum->m_print);
	pthread_mutex_lock(&coders->quantum->m_print);
	save = get_time() - coders->quantum->simulation_start;
	printf("%ld %d has taken a dongle\n", save, coders->index);
	pthread_mutex_unlock(&coders->quantum->m_print);
}

void	burnout_message(t_coders *coders)
{
	long			save;

	pthread_mutex_lock(&coders->quantum->m_print);
	save = get_time() - coders->quantum->simulation_start;
	printf("%ld %d burned out\n", save, coders->index);
	pthread_mutex_unlock(&coders->quantum->m_print);
}
