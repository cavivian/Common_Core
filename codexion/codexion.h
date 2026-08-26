/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:21 by cavivian          #+#    #+#             */
/*   Updated: 2026/08/25 23:13:52 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>

// struct perche' i coders non possono comunicare tra loro e ho bisogno che qualcuno
// controlli i tempi di esecuzione. Deve stampare anche il messaggio di errore entro 10ms.
// e deve stoppare l'eseuzione del programma.
typedef struct s_check
{
    pthread_t time_to_burnout;
    pthread_t number_of_compiles_required;
	pthread_t dongle_cooldown;
}	t_check;



// struct dei coders, che contiene le azioni che devono fare nel tempo stabilito
typedef struct s_coders
{
	int index;
    pthread_t coder_thread;
    pthread_mutex_t time_to_compile;
    pthread_mutex_t time_to_refactor;
    pthread_mutex_t time_to_debug;
    
}	t_coders;

t_coders *init_array(int size);
int parse(int argc, char **argv);
void *coderses(void *arg);
int join_threads(t_coders *cod, int i);
void	cleanup_all(t_coders *cod, int size);
void	cleanup(t_coders *cod, int i, int status);

#endif