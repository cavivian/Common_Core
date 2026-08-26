/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_mutex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 15:03:00 by camilla           #+#    #+#             */
/*   Updated: 2026/08/26 17:28:53 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

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
		
	}	
}
