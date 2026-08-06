/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:04 by cavivian          #+#    #+#             */
/*   Updated: 2026/08/06 17:18:25 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void *coders(void *args)
{
	
}

int	main(int argc, char *argv[])
{
	int	i;
	int	conv;
	int *arr;
	int k;
	pthread_t number_of_coders;

	if (argc != 2)
		return (0);
	i = 0;
	conv = atoi(argv[1]);
	arr = malloc(sizeof(int) * conv);
	if (!arr)
		return (0);
	while(i < conv && conv > 0)
	{
		arr[i] = pthread_create(&number_of_coders, NULL, &coders, NULL);
		i++;
	}
	return (0);
}
