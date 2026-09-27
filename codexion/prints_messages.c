/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_messages.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 12:04:03 by camilla           #+#    #+#             */
/*   Updated: 2026/09/27 22:31:14 by camilla          ###   ########.fr       */
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

// qui forse potrei aggiungere quella condizione che il messaggio va stampato entro 10 ms dal burnout
void	burnout_message(t_coders *coders)
{
	long			save;

	pthread_mutex_lock(&coders->quantum->m_print);
	save = get_time() - coders->quantum->simulation_start;
	printf("%ld %d burned out\n", save, coders->index);
	pthread_mutex_unlock(&coders->quantum->m_print);
}
