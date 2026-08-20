/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:21 by cavivian          #+#    #+#             */
/*   Updated: 2026/08/18 15:46:57 by camilla          ###   ########.fr       */
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
    pthread_mutex_t time_to_debug;
    pthread_mutex_t time_to_refactor;
    
}	t_coders;



#endif