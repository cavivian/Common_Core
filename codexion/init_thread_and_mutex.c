/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread_and_mutex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 15:03:00 by camilla           #+#    #+#             */
/*   Updated: 2026/09/30 12:06:37 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	init_coders_threads(t_coder *cod, int size, int *count)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (pthread_create(&cod[i].coder_thread, NULL, routine, &cod[i]) != 0)
		{
			return (1);
		}
		(*count)++;
		i++;
	}
	return (0);
}

void	init_monitor_threads(t_quantum *q)
{
	if (init_check_monitor(q) != 0)
		monitor_errors(q);
}

int	init_mutex(t_coder *cod, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (pthread_mutex_init(&cod[i].mutex, NULL) != 0)
		{
			cleanup_all(cod, i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	join_threads(t_coder *cod, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (pthread_join(cod[j].coder_thread, NULL) != 0)
			return (-(j + 1));
		j++;
	}
	return (0);
}
