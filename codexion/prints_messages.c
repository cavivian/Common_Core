/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_messages.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 12:04:03 by camilla           #+#    #+#             */
/*   Updated: 2026/09/29 14:30:15 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	compile_message(t_coder *coder)
{
	pthread_mutex_lock(&coder->quantum->m_simulation_stop);
	if (coder->quantum->simulation_stop == 0)
	{
		pthread_mutex_lock(&coder->quantum->m_print);
		printf("%ld %d is compiling\n", coder->last_compile_start
			- coder->quantum->simulation_start, coder->index);
		pthread_mutex_unlock(&coder->quantum->m_print);
	}
	pthread_mutex_unlock(&coder->quantum->m_simulation_stop);
}

void	debug_message(t_coder *coder)
{
	long			save;

	pthread_mutex_lock(&coder->quantum->m_simulation_stop);
	if (coder->quantum->simulation_stop == 0)
	{
		pthread_mutex_lock(&coder->quantum->m_print);
		save = get_time() - coder->quantum->simulation_start;
		printf("%ld %d is debugging\n", save, coder->index);
		pthread_mutex_unlock(&coder->quantum->m_print);
	}
	pthread_mutex_unlock(&coder->quantum->m_simulation_stop);
}

void	refactor_message(t_coder *coder)
{
	long			save;

	pthread_mutex_lock(&coder->quantum->m_simulation_stop);
	if (coder->quantum->simulation_stop == 0)
	{
		pthread_mutex_lock(&coder->quantum->m_print);
		save = get_time() - coder->quantum->simulation_start;
		printf("%ld %d is refactoring\n", save, coder->index);
		pthread_mutex_unlock(&coder->quantum->m_print);
	}
	pthread_mutex_unlock(&coder->quantum->m_simulation_stop);
}

void	take_dongle_message(t_coder *coder)
{
	long			save;

	pthread_mutex_lock(&coder->quantum->m_simulation_stop);
	if (coder->quantum->simulation_stop == 0)
	{
		pthread_mutex_lock(&coder->quantum->m_print);
		save = get_time() - coder->quantum->simulation_start;
		printf("%ld %d has taken a dongle\n", save, coder->index);
		pthread_mutex_unlock(&coder->quantum->m_print);
		pthread_mutex_lock(&coder->quantum->m_print);
		save = get_time() - coder->quantum->simulation_start;
		printf("%ld %d has taken a dongle\n", save, coder->index);
		pthread_mutex_unlock(&coder->quantum->m_print);
	}
	pthread_mutex_unlock(&coder->quantum->m_simulation_stop);
}

// qui forse potrei aggiungere quella condizione che
//il messaggio va stampato entro 10 ms dal burnout
void	burnout_message(t_coder *coder)
{
	long			save;

	pthread_mutex_lock(&coder->quantum->m_print);
	save = get_time() - coder->quantum->simulation_start;
	printf("%ld %d burned out\n", save, coder->index);
	pthread_mutex_unlock(&coder->quantum->m_print);
}
