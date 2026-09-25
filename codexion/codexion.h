/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:21 by cavivian          #+#    #+#             */
/*   Updated: 2026/09/25 13:22:23 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <time.h>
# include <string.h>

typedef struct s_coders		t_coders;
typedef struct s_quantum	t_quantum;
typedef struct s_dongle		t_dongle;

// enum per semplificare il parse dello scheduler 
typedef enum e_algorithm
{
	FIFO,
	EDF
}	t_algorithm;

// struct che contiene tutte le impostazioni riguardanti i coders e anche l'algoritmo 
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

typedef struct s_wait_node
{
	t_coders	*coder; // puntatore al coder che sta aspettando
	long		value; // quando ha fatto la richiesta
}	t_wait_node;

// struct che contiene l'heap, si occupa di gestire la priorità dei coder che stanno aspettando le dongle
typedef struct s_heap
{
	t_wait_node	array[2];
	int			size;
	int			current_size;
}	t_heap;

// struct che dentro di sè contiene le info che ripesca da settings
// non va mallocato, alloca e freea da sè
typedef struct s_quantum
{
	int				simulation_stop;
	long			simulation_start;
	pthread_mutex_t	m_simulation_stop;
	t_settings		config;
	pthread_mutex_t	m_print;
	pthread_t		monitor_thread;
	pthread_cond_t	service_condition;
	pthread_mutex_t	service_mutex;
	t_heap			wait_heap; // heap che contiene i coder che stanno aspettando le dongle
	t_coders		*coders;
}	t_quantum;

// struct che contiene le info sullo stato delle dongle, se sono disponibili o meno
typedef struct s_dongle
{
	pthread_mutex_t	m_dongle; // dice se qualcuno in questo momento sta usando la dongle
	long			t_available_dongle; // dice da quale momento è possibile prendere la dongle dopo il cooldown
	int				is_not_available;
	t_heap			heap;
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

// struct che contiene il coder e il momento in cui ha fatto la richiesta (per FIFO)
// o il momento in cui ha fatto l'ultima compilazione (per EDF)



// struct che contiene tutte le info che servono al monitor per controllare lo stato della simulazione


int			validation(int argc, char **argv);
int			parse(t_quantum *q, int argc, char **argv);
void		get_time(t_quantum *q);
t_dongle	*init_array_dongle(t_quantum *q);
t_coders	*init_array_coders(t_quantum *q, t_dongle *dongle);
int			central_part(t_quantum *q, int count, t_dongle *dongle);
int			init_check_monitor(t_quantum *q, t_coders *cod);
int			compile(t_coders *cod);
int			debug(t_coders *coders);
int			refactor(t_coders *coders);
int			check_less_zero(char **argv);
void		*coderses(void *arg);
t_coders	*give_dongle(t_coders *cod, t_dongle *dongle, int size);
long		get_eta_cooldown_time(t_dongle *dongle);
int			if_dongle_is_available(t_coders *coder);
int			centre(t_coders *coders, long actually_time, struct timespec *ts);
void		lock_unlock_of_mutex(t_coders *coders);
void		cleanup(t_dongle *dongle, int i);
void		cleanup_all(t_coders *cod, int size);
int			check_simulation(t_coders *coders);
int			init_coders_threads(t_coders *cod, int size, int *count);
int			init_mutex(t_coders *cod, int size);
int			join_threads(t_coders *cod, int i);
int			check_n_of_compiles(t_quantum *q);
void		simulation_stop_is_1(t_quantum *q);
int			if_burnout(t_quantum *q, long save);
void		monitor_centre(t_quantum *q);
void		*monitor(void *arg);
int			init_check_monitor(t_quantum *q, t_coders *cod);
void		compile_message(t_coders *coders);
void		debug_message(t_coders *coders);
void		refactor_message(t_coders *coders);
void		take_dongle_message(t_coders *coders);
void		burnout_message(t_coders *coders);
void		ft_swap(t_wait_node *a, t_wait_node *b);
//t_heap		init_array_heap(int size);
t_wait_node	create_wait_node(t_coders *coder, t_algorithm algo);
void		free_heap(t_heap *heap);
int			creation_arrays(t_coders **coders, t_quantum *q,
				t_dongle **dongle);
int			heap_father(int i);
int			heap_left_son(int i);
int			heap_right_son(int i);
int			delete_max_priority_node(t_heap *heap, t_wait_node *extract_node);
t_heap		*push_into_the_heap(t_heap *heap, t_wait_node node);
void		check_priority_queue(t_heap *heap, int index);
void		actions(t_coders *coders);
void		init_coders_values(int i, t_coders *coders, t_quantum *q);
int			handle_coders_thread(t_coders *coders, int num,
				t_dongle *dongle, int *count);
void		mutex_unlock(t_coders *cod);
void		init_monitor_threads(t_quantum *q);
int			monitor_errors(t_quantum *q);
void		register_heap(t_coders *coder);
void		apply_cooldown(t_coders *coder);



#endif