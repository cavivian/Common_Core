/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:21 by cavivian          #+#    #+#             */
/*   Updated: 2026/09/03 12:07:30 by camilla          ###   ########.fr       */
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
#include <string.h>


// enum per semplificare il parse dello scheduler 
typedef enum e_algorithm
{
	FIFO,
	EDF
}	t_algorithm;


// struct che contine tutte le impostazioni riguardanti i coders e anche l'algoritmo 
// che va scelto
// sono di tipo int e non pthread perchè sono tempi
typedef struct s_settings
{
	int			n_of_coders;	
	int			burnout;
	int			compile;
	int			debug;
	int			refactor;
	int			number_of_compiles_required;
	int			dongle_cooldown;

	t_algorithm	algorithm;
	
}	t_settings;


// struct che dentro di sè contiene le info che ripesca da settings
// non va mallocato, alloca e freea da sè
typedef struct s_quantum
{
	int				simulation_stop;
	long			simulation_start;
	pthread_mutex_t m_simulation_stop;
	t_settings		config;
	pthread_mutex_t	m_print;
	pthread_t		monitor_thread;
}	t_quantum;


// struct perche' i coders non possono comunicare tra loro e ho bisogno che qualcuno
// controlli i tempi di esecuzione. Deve stampare anche il messaggio di errore entro 10ms.
// e deve stoppare l'esecuzione del programma.


// struct che ci serve per capire lo stato di una chiavetta
// per rendere sicuro che un coder alla volta la prenda
// anche perchè dentro il suo lock e unlock ci vanno tutti i tempi di esecuzione, e la chiavetta non 
// può essere usata dal coder accanto e per evitare che venga duplicata
typedef struct s_dongle
{
	pthread_mutex_t m_dongle; // dice se qualcuno in questo momento sta usando la dongle
	long			t_available_dongle; // dice tra quanto si può riprendere se è stato restituito
	// altre info
}	t_dongle;


// struct dei coders, che ripesca dentro quantum i parametri
// che i coders devono rispettare per eseguire le azioni 
typedef struct s_coders
{
	int				index;
	pthread_t		coder_thread;
	pthread_mutex_t	mutex; // mutex per ogni coder che si crea
	
	t_dongle		*dongle_sx; // controllo per la dongle sx
	t_dongle		*dongle_dx; // controllo per la dongle dx
	long			last_compile_start;
	int				n_of_compiles;
	
	
	t_quantum		*quantum; // ripescaggio di tutti i parametri di esecuzione
}	t_coders;

typedef struct s_check
{
	int				*number_of_compiles_required;
	int				*burnout;
	int				*dongle_cooldown;
	int				*simulation_stop;
	t_coders		*coders;
	int				n_of_coders;
	pthread_mutex_t	*m_simulation_stop;
	t_dongle		*dongles;
}	t_check;




t_coders 	*init_array_coders(t_quantum *q);
int			parse(t_quantum *q, int argc, char **argv);
void		*coderses(void *arg);
int			join_threads(t_coders *cod, int i);
void		cleanup_all(t_coders *cod, int size, int result);
void		cleanup(t_dongle *dongle, int i);
int			validation(int argc, char **argv);
t_dongle	*init_array_dongle(t_quantum *q);
void		cleanup_coders(t_coders *cod, int size);
void		*monitor(void *arg);
int			init_check_monitor(t_check *check, t_quantum *q, t_coders *cod);
void		if_burnout(t_check *check, long save);
int			if_dongle_is_available(t_coders *coders);
int			compile(t_coders *cod);



#endif