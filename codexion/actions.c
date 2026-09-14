/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 14:17:36 by camilla           #+#    #+#             */
/*   Updated: 2026/09/14 15:43:45 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	compile(t_coders *cod) // finita per ora
{
	struct timeval	tv;
	long			time_save;
	
	if (if_dongle_is_available(cod) != 1) // controlla che la dongle sx e dx siano accessibili in contemporanea
	{
		take_dongle_message(cod);
		gettimeofday(&tv, NULL);
		time_save = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000)); // espressione per ottenere gli ms
		// deve essere protetta da un mutex
		pthread_mutex_lock(&cod->mutex);
		cod->last_compile_start = time_save; // e si salva quando è iniziata l'ultima compilazione
		pthread_mutex_unlock(&cod->mutex);
		compile_message(cod);
		usleep(cod->quantum->config.compile * 1000); // tempo di compilazione
		gettimeofday(&tv, NULL); // si ricalcola il tempo attuale
		time_save = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000)); // si ricalcola in ms
		cod->dongle_dx->t_available_dongle = time_save + cod->quantum->config.dongle_cooldown; // calcolo tempo di riposo della dongle
		cod->dongle_sx->t_available_dongle = time_save + cod->quantum->config.dongle_cooldown; // calcolo tempo di riposo della dongle
		pthread_mutex_unlock(&cod->dongle_dx->m_dongle); // si unlockano qui, pk vengono lockate dentro if_dongle_is_available
		pthread_mutex_unlock(&cod->dongle_sx->m_dongle); // uguale a quella sopra
		pthread_cond_broadcast(&cod->quantum->service_condition);
		// la chiamata al broadcast va fatta dopo l'unlock, perchè se lo svegli prima e uno dei due dongle non è disponibile
		// continua a girare nel while finchè non si sbloccano entrambi.
		return (0);
	}
	return (1);
}


int	debug(t_coders *coders) // finita
{
	debug_message(coders);
	usleep(coders->quantum->config.debug * 1000);
	return (0);
}


int	refactor(t_coders *coders) // finita
{
	refactor_message(coders);
	usleep(coders->quantum->config.refactor * 1000);
	return (0);
}
