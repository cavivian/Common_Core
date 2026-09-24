/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_error_management.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:49:40 by camilla           #+#    #+#             */
/*   Updated: 2026/09/24 18:44:42 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// controlla che tutti i coder abbiano completato i compile richiesti
int	check_n_of_compiles(t_quantum *q)
{
	int	i;
	int	check_of_compile;

	i = 0;
	//printf("\nsono dentro check_n_of_compiles");
	while (i < q->config.n_of_coders)
	{
		pthread_mutex_lock(&q->coders[i].mutex);
		check_of_compile = q->coders[i].n_of_compiles;
		//printf("\n sono dentro il mutex del q_of_compile\n");
	//	printf("\n%d number of compiles\n", q->coders[i].n_of_compiles);
	//	printf("\n%d compiles\n", q_of_compile);
		pthread_mutex_unlock(&q->coders[i].mutex);
		if (check_of_compile < q->config.number_of_compiles_required)
		{
			//printf("\nsto ritornando errore\n");
			return (1);
		}
		i++;
	}
	return (0);
}

// imposta il simulation stop a 1
void	simulation_stop_is_1(t_quantum *q)
{
	pthread_mutex_lock(&q->m_simulation_stop);
	q->simulation_stop = 1;
	pthread_mutex_unlock(&q->m_simulation_stop);
}
