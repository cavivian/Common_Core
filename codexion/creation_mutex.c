/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_mutex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 15:03:00 by camilla           #+#    #+#             */
/*   Updated: 2026/08/26 23:50:34 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

pthread_t	*init_threads(int size)
{
	int	i;
	pthread_t	*cod_thread;

	cod_thread = malloc(sizeof(pthread_t) * size);
	if (!cod_thread)
		return (NULL);
	i = 0;
	while(i < size)
	{
		if (pthread_create(&cod_thread[i], NULL, coderses, NULL) != 0)
		{
			free(cod_thread);
			return (NULL);
		}
		i++;
	}
	return (cod_thread);
}


t_dongle	*init_array_dongle(t_quantum *q)
{
	int	number;
	t_dongle *dongle;
	int	i;

	number = q->config.n_of_coders;
	i = 0;
	dongle = malloc(sizeof(t_dongle) * number);
	if (!dongle)
		return (NULL);
	memset(dongle, 0, number * sizeof(t_dongle));
	while(i < number)
	{
		if (pthread_mutex_init(&dongle[i].m_dongle, NULL) != 0)
		{
			cleanup(dongle, i);
			return NULL;
		}
		i++;
	}
	return (dongle);
}


t_coders *init_array_coders(t_quantum *q)
{
	int i;
	t_coders *coders;
	int num;

	num = q->config.n_of_coders;
	coders = malloc(sizeof(t_coders) * num);
	if (!coders)
		return (NULL);
	memset(coders, 0, num * sizeof(t_coders));
	i = 0;
	while (i < coders)
	{
		coders[i].index = i;
		coders[i].coder_thread = init_threads(num);
		coders[i].mutex = "ciao";
	}	
}
