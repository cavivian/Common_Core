/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 09:43:51 by cavivian          #+#    #+#             */
/*   Updated: 2026/10/01 17:32:47 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	init_coders_values(int i, t_coder *coder, t_quantum *q)
{
	coder[i].quantum = q;
	coder[i].last_compile_start = q->simulation_start;
	coder[i].n_of_compiles = 0;
	coder[i].index = i + 1;
}

int	handle_coders_thread(t_coder *coder, int num,
	t_dongle *dongle, int *count)
{
	if (init_mutex(coder, num) != 0)
		return (1);
	give_dongle(coder, dongle, num);
	if (init_coders_threads(coder, num, count) != 0)
	{
		if (join_threads(coder, *count) != 0)
			return (1);
		cleanup_all(coder, num);
		return (1);
	}
	return (0);
}

t_coder	*init_array_coders(t_quantum *q)
{
	int			i;
	t_coder		*coder;
	int			num;

	num = q->config.n_of_coders;
	coder = malloc(sizeof(t_coder) * num);
	if (!coder)
		return (NULL);
	memset(coder, 0, num * sizeof(t_coder));
	i = 0;
	while (i < num)
	{
		init_coders_values(i, coder, q);
		i++;
	}
	return (coder);
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
		dongle[i].heap.size = 2;
		if (pthread_mutex_init(&dongle[i].m_dongle, NULL) != 0)
		{
			cleanup_dongle(dongle, number);
			return (NULL);
		}
		i++;
	}
	return (dongle);
}

int	creation_arrays(t_quantum *q,
	t_dongle **dongle)
{
	*dongle = init_array_dongle(q);
	if (!*dongle)
		return (1);
	q->coder = init_array_coders(q);
	if (!q->coder)
		return (1);
	return (0);
}
