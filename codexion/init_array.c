/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 09:43:51 by cavivian          #+#    #+#             */
/*   Updated: 2026/09/22 17:47:51 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	init_coders_values(int i, t_coders *coders, t_quantum *q)
{
	coders[i].quantum = q;
	coders[i].last_compile_start = q->simulation_start;
	coders[i].n_of_compiles = 0;
	coders[i].index = i + 1;
}

int	handle_coders_thread(t_coders *coders, int num,
	t_dongle *dongle, int *count)
{
	if (init_mutex(coders, num) != 0)
		return (1);
	give_dongle(coders, dongle, num);
	if (init_threads(coders, num, count) != 0)
	{
		if (join_threads(coders, *count) != 0)
			return (1);
		cleanup_all(coders, num);
		return (1);
	}
	return (0);
}

t_coders	*init_array_coders(t_quantum *q, int *count, t_dongle *dongle)
{
	int			i;
	t_coders	*coders;
	int			num;

	num = q->config.n_of_coders;
	coders = malloc(sizeof(t_coders) * num);
	if (!coders)
		return (NULL);
	memset(coders, 0, num * sizeof(t_coders));
	i = 0;
	while (i < num)
	{
		init_coders_values(i, coders, q);
		i++;
	}
	if (handle_coders_thread(coders, num, dongle, count) != 0)
		return (NULL);
	return (coders);
}

t_dongle	*init_array_dongle(t_quantum *q)
{
	int			number;
	t_dongle	*dongle;
	int			i;

	number = q->config.n_of_coders;
	i = 0;
	dongle = malloc(sizeof(t_dongle) * number);
	if (!dongle)
		return (NULL);
	memset(dongle, 0, number * sizeof(t_dongle));
	while (i < number)
	{
		if (pthread_mutex_init(&dongle[i].m_dongle, NULL) != 0)
		{
			cleanup(dongle, number);
			return (NULL);
		}
		i++;
	}
	return (dongle);
}
