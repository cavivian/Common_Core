/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 09:36:04 by camilla           #+#    #+#             */
/*   Updated: 2026/08/27 12:52:30 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

t_coders	*give_dongle(t_coders *cod, t_dongle *dongle, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i == 0)
		{
			cod[i].dongle_sx = &dongle[size - 1];
			cod[i].dongle_dx = &dongle[i + 1];
		}
		else
		{
			if (i == size - 1)
			{
				cod[i].dongle_dx = &dongle[0];
				cod[i].dongle_sx = &dongle[i];
			}
			else
			{
				cod[i].dongle_dx = &dongle[i + 1];
				cod[i].dongle_sx = &dongle[i];	
			}
		}
		i++;
	}
	return (cod);
}
