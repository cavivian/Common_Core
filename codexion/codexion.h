/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:21 by cavivian          #+#    #+#             */
/*   Updated: 2026/09/29 14:32:50 by cavivian         ###   ########.fr       */
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

typedef struct s_coder		t_coder;
typedef struct s_quantum	t_quantum;
typedef struct s_dongle		t_dongle;

typedef enum e_algorithm
{
	FIFO,
	EDF
}	t_algorithm;

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
	t_coder		*coder;
	long		value;
}	t_wait_node;

typedef struct s_heap
{
	t_wait_node	array[2];
	int			size;
	int			current_size;
}	t_heap;

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
	t_heap			wait_heap;
	t_coder			*coder;
}	t_quantum;

typedef struct s_dongle
{
	pthread_mutex_t	m_dongle;
	long			t_available_dongle;
	int				is_not_available;
	t_heap			heap;
}	t_dongle;

typedef struct s_coder
{
	int				index;
	pthread_t		coder_thread;
	pthread_mutex_t	mutex;
	t_dongle		*dongle_sx;
	t_dongle		*dongle_dx;
	long			last_compile_start;
	int				n_of_compiles;
	t_quantum		*quantum;
}	t_coder;

int			validation(int argc, char **argv);
int			parse(t_quantum *q, int argc, char **argv);
void		init_simulation_and_mutex(t_quantum *q);
t_dongle	*init_array_dongle(t_quantum *q);
t_coder		*init_array_coders(t_quantum *q);
int			join_and_clean(t_quantum *q, int count, t_dongle *dongle);
int			init_check_monitor(t_quantum *q, t_coder *cod);
int			compile(t_coder *cod);
int			debug(t_coder *coder);
int			refactor(t_coder *coder);
int			check_less_zero(char **argv);
void		*routine(void *arg);
t_coder		*give_dongle(t_coder *cod, t_dongle *dongle, int size);
long		get_eta_cooldown_time(t_dongle *dongle);
int			if_dongle_is_available(t_coder *coder);
int			centre(t_coder *coders, long actually_time);
void		lock_unlock_of_mutex(t_coder *coder);
void		cleanup_dongle(t_dongle *dongle, int i);
void		cleanup_all(t_coder *cod, int size);
int			check_simulation(t_coder *coder);
int			init_coders_threads(t_coder *cod, int size, int *count);
int			init_mutex(t_coder *cod, int size);
int			join_threads(t_coder *cod, int i);
int			check_n_of_compiles(t_quantum *q);
void		simulation_stop_is_1(t_quantum *q);
int			if_burnout(t_quantum *q, long save);
void		monitor_centre(t_quantum *q);
void		*monitor(void *arg);
int			init_check_monitor(t_quantum *q, t_coder *cod);
void		compile_message(t_coder *coder);
void		debug_message(t_coder *coder);
void		refactor_message(t_coder *coder);
void		take_dongle_message(t_coder *coder);
void		burnout_message(t_coder *coder);
void		ft_swap(t_wait_node *a, t_wait_node *b);
t_wait_node	create_wait_node(t_coder *coder, t_algorithm algo);
void		free_heap(t_heap *heap);
int			creation_arrays(t_quantum *q,
				t_dongle **dongle);
int			heap_father(int i);
int			heap_left_son(int i);
int			heap_right_son(int i);
int			delete_max_priority_node(t_heap *heap);
t_heap		*push_into_the_heap(t_heap *heap, t_wait_node node);
void		check_priority_queue(t_heap *heap, int index);
void		actions(t_coder *coder);
void		init_coders_values(int i, t_coder *coder, t_quantum *q);
int			handle_coders_thread(t_coder *coder, int num,
				t_dongle *dongle, int *count);
void		init_monitor_threads(t_quantum *q);
int			monitor_errors(t_quantum *q);
void		register_heap(t_coder *coder);
void		apply_cooldown(t_coder *coder);
long		get_time(void);
void		freedom_dongle(t_dongle *dongle, pthread_mutex_t *m_dongle,
				long time_save);
int			only_one_coder(t_coder *coder);

#endif