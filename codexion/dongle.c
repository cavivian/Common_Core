/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 09:36:04 by camilla           #+#    #+#             */
/*   Updated: 2026/09/19 10:28:26 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// devo gestire quando il coder è uno solo, ma lo gestisco in un'altra funzione
t_coders	*give_dongle(t_coders *cod, t_dongle *dongle, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		//if_dongle_is_available(cod);
		//pthread_mutex_lock(&dongle->m_dongle);
		// assegnazione delle dongle
		cod[i].dongle_sx = &dongle[i];
		cod[i].dongle_dx = &dongle[(i + 1) % cod->quantum->config.n_of_coders];
		if (i == 0)
		{
			cod[i].dongle_sx = cod[i].dongle_dx;
			cod[i].dongle_dx = &dongle[i];
		}
		//pthread_mutex_unlock(&dongle->m_dongle);
		i++;
	}
	return (cod);
}


long	check_available_dongle(t_dongle *dongle)
{
	long	available;

	available = 0;
	pthread_mutex_lock(&dongle->m_dongle);
	available = dongle->t_available_dongle;
	pthread_mutex_unlock(&dongle->m_dongle);
	return (available);
}

void	centre(t_coders *coders, int actually_time, struct timespec *ts)
{
	struct timeval	tv;

	while(check_available_dongle(coders->dongle_sx) > actually_time // risponde alla domanda "in questo istante, il dongle è disponibile, o è in cooldown?"
	|| check_available_dongle(coders->dongle_dx) > actually_time) // controllo dal momento in cui le dongle tornano libere, fino al tempo attuale
	{
		gettimeofday(&tv, NULL); // deve aggiornarsi a ogni ciclo
		actually_time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
		if(check_simulation(coders) != 0) // se la simulazione è finita(burnout o tutti i coder hanno finito) rilascia la dongle
		{
			pthread_mutex_unlock(&coders->quantum->service_mutex);
			return ;
		}
		else if (pthread_cond_timedwait(&coders->quantum->service_condition,
		&coders->quantum->service_mutex, ts) != 0) // rilascia il mutex che fermava il controllo 
		// della disponibilità, per permettere agli altri coder di andare avanti.
		// stoppa il thread finchè qualcuno non chiama cond_broadcast/signal oppure va in burnout
		{
			pthread_mutex_unlock(&coders->quantum->service_mutex);
			return ;
		}
		// se ha successo controlla di nuovo che le dongle rilasciate siano compatibili con il coder svegliato
	}
}

void	lock_unlock_of_mutex(t_coders *coders)
{
	pthread_mutex_lock(&coders->dongle_sx->m_dongle);
	pthread_mutex_lock(&coders->dongle_dx->m_dongle);
	pthread_mutex_unlock(&coders->quantum->service_mutex);
}
// controlla se è possibile prendere due dongle in contemporanea
// qui manca la chiamata a FIFO e EDF
// manca caso un solo coder
// t_available_dongle in check_available_dongle è un punto preciso, non è una durata
// save mi dice per quanto tempo posso stare nel ciclo prima di raggiungere il burnout
int	if_dongle_is_available(t_coders *coders) 
{
	struct timespec	ts;
	struct timeval	tv;
	long			save;
	long			actually_time;
	t_wait_node		node;
	
	save = (coders->last_compile_start + coders->quantum->config.burnout); //  calcolo della propria deadline personale di burnout
	ts.tv_sec = save / 1000;
	ts.tv_nsec = (save % 1000) * 1000000; // parametri che vanno passati al timedwait
	gettimeofday(&tv, NULL);
	actually_time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000)); // conversione in millisecondi
	node = create_wait_node(coders->quantum->wait_heap, coders,
			coders->quantum->config.algorithm);
	pthread_mutex_lock(&coders->quantum->service_mutex);
	gettimeofday(&tv, NULL); // calcolo del momento attuale per sapere se al momento le dongle sono disponibili
	actually_time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000)); // conversione in millisecondi
	push_into_the_heap(coders->quantum->wait_heap, &node);
	centre(coders, actually_time, &ts); // controllo se le dongle sono disponibili, e se non lo sono, addormento il thread finchè non lo diventano
	lock_unlock_of_mutex(coders); // se le dongle sono disponibili, le blocco e rilascia il mutex del service
	return(0);
}

// utilizzo di pthread_cond_timedwait()e pthread_cond_wait():
// permettono di addormentare un thread finchè una certa condizione non si verifica senza consumare CPU
// e di essere risvegliato dall'OS quando quel qualcosa accade(grazie a broadcast/signal, fatti da un'altro thread)
// cond_wait fa il rilascio del mutex e l'addormentamento del thread in un unico passaggio, perchè potrebbe succedere che tra un 
// passaggio e l'altro un altro thread faccia il suo broadcast, e quello addormentato rimanga così per sempre. è per maggiore sicurezza
// ma la differenza con timedwait sta nel fatto che quest'ultimo lo fa con un'uscita di sicurezza: ovvero se arriva all'istante
// assoluto della deadline, fa risvegliare il thread, e la funzione ritorna un messaggio di default di errore.
// pthread_cond_wait invece aspetterebbe per sempre