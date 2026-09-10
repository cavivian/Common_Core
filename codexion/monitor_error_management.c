/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_error_management.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:49:40 by camilla           #+#    #+#             */
/*   Updated: 2026/09/09 17:08:52 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// controlla che tutti i coder abbiano completato i compile richiesti
int check_n_of_compiles(t_check *check)
{
	int i;

	i = 0;
	while(i < check->n_of_coders)
	{
		if (check->coders[i].n_of_compiles < *check->number_of_compiles_required)
			return (1);
		i++;
	}
	return (0);
}

// imposta il simulation stop a 1
void	simulation_stop_is_1(t_check *check)
{
	pthread_mutex_lock(check->m_simulation_stop);
	*check->simulation_stop = 1;
	pthread_mutex_unlock(check->m_simulation_stop);
}