/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 09:36:04 by camilla           #+#    #+#             */
/*   Updated: 2026/08/31 11:15:25 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

t_coders	*give_dongle(t_coders *cod, t_dongle *dongle, int size)
{
	int	i;

	i = 0;
	if (size == 1) // se abbiamo un solo coder, abbiamo anche una sola dongle
	{
		cod[i].dongle_dx = &dongle[0];
		cod[i].dongle_sx = &dongle[0];
	}
	else
	{
		while (i < size)
		{
			if (i == 0) // se e' il primo coder
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
	}
	return (cod);
}
