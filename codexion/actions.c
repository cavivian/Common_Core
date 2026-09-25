/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 14:17:36 by camilla           #+#    #+#             */
/*   Updated: 2026/09/25 17:49:51 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// ultima parte di coderses
void	actions(t_coders *coders)
{
	pthread_mutex_lock(&coders->mutex);
	coders->n_of_compiles++;
	pthread_mutex_unlock(&coders->mutex);
	if (check_simulation(coders) != 0)
		return ;
	if (debug(coders) != 0)
		return ;
	if (check_simulation(coders) != 0)
		return ;
	if (refactor(coders) != 0)
		return ;
}

// funzione che crea il nodo e lo passa a heap
void	register_heap(t_coders *coder)
{
	t_wait_node	node;

	node = create_wait_node(coder, coder->quantum->config.algorithm);
	push_into_the_heap(&coder->dongle_sx->heap, node);
	printf("\n%d [lct: %ld] entrato in push_into_the_heap. current nodes: (DONGLE_SX) [0]: %p (value: %ld), [1]: %p (value: %ld)\n", coder->index, coder->last_compile_start,
		coder->dongle_sx->heap.array[0].coder, coder->dongle_sx->heap.array[0].value, coder->dongle_sx->heap.array[1].coder, coder->dongle_sx->heap.array[1].value);
	push_into_the_heap(&coder->dongle_dx->heap, node);
	printf("\n%d [lct: %ld] entrato in push_into_the_heap. current nodes: (DONGLE_DX) [0]: %p (value: %ld), [1]: %p (value: %ld)\n", coder->index, coder->last_compile_start,
		coder->dongle_dx->heap.array[0].coder, coder->dongle_dx->heap.array[0].value, coder->dongle_dx->heap.array[1].coder, coder->dongle_dx->heap.array[1].value);
}

//  controlla che la dongle sx e dx siano accessibili in contemporanea
// t_available_dongle = tempo in millisecondi in cui la dongle sarà disponibile
// m_dongle = mutex che dice se la dongle è in uso o meno
// chiamata a boadcast per svegliare i thread in attesa di una dongle
int	compile(t_coders *cod)
{
	long			time_save;

	register_heap(cod);
	while (check_simulation(cod) != 1)
		if (if_dongle_is_available(cod) != 1)
			break ;
	take_dongle_message(cod);
	time_save = get_time();
	pthread_mutex_lock(&cod->mutex);
	cod->last_compile_start = time_save;
	pthread_mutex_unlock(&cod->mutex);
	compile_message(cod);
	usleep(cod->quantum->config.compile * 1000);
	time_save = get_time();
	pthread_mutex_lock(&cod->dongle_dx->m_dongle);
	cod->dongle_dx->t_available_dongle = (time_save
		+ cod->quantum->config.dongle_cooldown);
	cod->dongle_dx->is_not_available = 0;
	pthread_mutex_unlock(&cod->dongle_dx->m_dongle);
	pthread_mutex_lock(&cod->dongle_sx->m_dongle);
	cod->dongle_sx->t_available_dongle = (time_save
		+ cod->quantum->config.dongle_cooldown);
	cod->dongle_sx->is_not_available = 0;
	return (pthread_mutex_unlock(&cod->dongle_sx->m_dongle), 0);
}

int	debug(t_coders *coders)
{
	debug_message(coders);
	usleep(coders->quantum->config.debug * 1000);
	return (0);
}

int	refactor(t_coders *coders)
{
	refactor_message(coders);
	usleep(coders->quantum->config.refactor * 1000);
	return (0);
}
