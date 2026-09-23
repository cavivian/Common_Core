/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 09:36:25 by cavivian          #+#    #+#             */
/*   Updated: 2026/09/23 10:57:32 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	validation(int argc, char **argv)
{
	int	args;
	int	i;

	args = 1;
	i = 0;
	while (args < argc - 1)
	{
		i = 0;
		if (argv[args][i] == '\0')
			return (1);
		while (argv[args][i])
		{
			if (!(argv[args][i] >= '0' && argv[args][i] <= '9'))
				return (1);
			i++;
		}
		args++;
	}
	if (strcmp(argv[8], "edf") != 0 && strcmp(argv[8], "fifo") != 0)
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
