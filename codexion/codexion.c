/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:04 by cavivian          #+#    #+#             */
/*   Updated: 2026/09/14 15:43:23 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// funzione "main" che conterra' tutto il loop delle azioni dei vari coders
// qua dentro va creato il ciclo while che diceva ieri Edo
void	*coderses(void *arg) // finita per adesso
{
	t_coders *coders = (t_coders *)arg;
	int	i;
	
	i = 0;
	while(i < coders->quantum->config.number_of_compiles_required)
	{
		if (check_simulation(coders) != 0)
			return (NULL);
		if (compile(coders) != 0)
		{
			usleep(10000);
			continue;
		}
		pthread_mutex_lock(&coders->mutex);
		coders->n_of_compiles++; // deve essere protetto, perchè ci sta che due thread lo vedano nello stesso momento
		pthread_mutex_unlock(&coders->mutex);
		if (check_simulation(coders) != 0)
			return (NULL);
		if (debug(coders) != 0)
			return (NULL);
		if (check_simulation(coders) != 0)
			return (NULL);
		if (refactor(coders) != 0)
			return (NULL);
		i++;
	}
	printf("\nthread creato!\n");
	return (NULL);
}
// 	t_coders *codx = malloc(sizeof(t_coders)); // Edo lo aveva scritto con un (coders[1] * sizeof(t_coders))



// parte del parse per controllare che i primi 7 arg siano int
// e che l'ultimo sia una stringa, controllo con strcmp
// questa funzione accetta che i primi 7 argomenti possano essere 0, sbagliato!
int	validation(int argc, char **argv) // finita
{
	int	args;
	int	i;

	args = 1;
	i = 0;
	while(args < argc - 1) // si scorre args finchè è minore di argc
	{
		i = 0;
		if (argv[args][i] == '\0') // controlla che non venga passata una stringa vuota
			return (1);
		while(argv[args][i]) // controllo che siano passati solo numeri
		{
			if (!(argv[args][i] >= '0' && argv[args][i] <= '9'))
				return (1);
			i++;
		}
		args++;
	}
	if (strcmp(argv[8], "edf") != 0 && strcmp(argv[8], "fifo") != 0) // controlla che l'ultimo parametro sia o edf o fifo
			return (1);
	return (0);
}


int	check_less_zero(char **argv)
{
	int	check_coders;
	int	check_burnout;
	int	check_compile_required;

	check_coders = atoi(argv[1]);
	check_burnout = atoi(argv[2]);
	check_compile_required = atoi(argv[6]);
	if (check_coders <= 0 || check_burnout <= 0 || check_compile_required <= 0)
		return (1);
	return (0);
}
// parse che chiama validation
// controlla che tutti i parametri passati siano int
// e li assegna a ogni variabile della struct quantum 
int	parse(t_quantum *q, int argc, char **argv) // finita
{
	if (validation(argc, argv) != 0)
		return (1);
	if (check_less_zero(argv) != 0)
		return (1);
	if (!strcmp(argv[8], "fifo"))
		q->config.algorithm = FIFO;
	else if (!strcmp(argv[8], "edf"))
		q->config.algorithm = EDF;
	q->config.n_of_coders = atoi(argv[1]);
	q->config.burnout = atoi(argv[2]);
	q->config.compile = atoi(argv[3]);
	q->config.debug = atoi(argv[4]);
	q->config.refactor = atoi(argv[5]);
	q->config.number_of_compiles_required = atoi(argv[6]);
	q->config.dongle_cooldown = atoi(argv[7]);
	return (0);	
}


int	central_part(t_quantum *q,  int count, t_coders *coders, t_check *check, t_dongle *dongle)
{
	 // in questa funzione quindi vanno creati i thread veri e propri,
	if (coders == NULL)
		return (1);
	if (init_check_monitor(check, q, coders) != 0)
	{
		join_threads(coders, count);
		cleanup_all(coders, q->config.n_of_coders);
		pthread_mutex_destroy(&q->m_simulation_stop);
		pthread_mutex_destroy(&q->m_print);
		pthread_mutex_destroy(&q->service_mutex);
		pthread_cond_destroy(&q->service_condition);
		cleanup(dongle, count);
		return (1);
	}
	join_threads(coders, count);
	if (pthread_join(q->monitor_thread, NULL) != 0)
		return (1);
	cleanup_all(coders, q->config.n_of_coders);
	cleanup(dongle, count);
	pthread_mutex_destroy(&q->m_simulation_stop);
	pthread_mutex_destroy(&q->m_print);
	pthread_mutex_destroy(&q->service_mutex);
	pthread_cond_destroy(&q->service_condition);
	return (0);
}


void	get_time(t_quantum *q)
{
	struct timeval	tv;

	q->simulation_stop = 0; // è 0 perchè non è finita, la simulazione deve ancora iniziare
	gettimeofday(&tv, NULL); // si ricava l'ora attuale
	q->simulation_start = (tv.tv_sec * 1000) + (tv.tv_usec / 1000); // si inizia la simulazione dei tempi 
	pthread_mutex_init(&q->m_simulation_stop, NULL); // si inizializza il mutex della simulation stop
	pthread_mutex_init(&q->m_print, NULL);
	pthread_mutex_init(&q->service_mutex, NULL);
	pthread_cond_init(&q->service_condition, NULL);
}

//qua dentro ci  stanno le chiamate alle funzioni. prima parse
// poi creazione thread, e la creazione dell'array preso dal parse
// se il parse fallisce il programma deve terminare
int	main(int argc, char *argv[])
{
	t_quantum		q; // struct che contiene i riferimenti ai valori dei coders
	t_check			check; // struct che fa il controllo dei tempi
	int				count;
	t_dongle		*dongle;
	
	count = 0;
	if (argc != 9)
		return 0;
	memset(&check, 0, sizeof(t_check));
	if (validation(argc, argv) == 0)
	{
		t_coders	*coders; // array di struct che contiene i thread che compongono le struct con i vari  dati dei vari coders
		if (parse(&q, argc, argv) == 0)
		{
			get_time(&q);
			dongle = init_array_dongle(&q);
			if (!dongle)
				return (1);
			coders = init_array_coders(&q, &count, dongle);
			// qui dentro ci sta la creazione del monitor, i vari join e i destroy
			if(central_part(&q, count, coders, &check, dongle) != 0)
				return (1);
		}
		return (0);
	}	// qui va passato il parse, se va a buon fine prosegue, altrimenti si ferma il programma
	return (1);
}
