/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:04 by cavivian          #+#    #+#             */
/*   Updated: 2026/08/17 17:55:49 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"


// funzione "main"  che conterra' tutto il loop delle azioni dei vari coders
void *coders(void *args)
{
	
}


// c'e'da fare una funzione che faccia il parse e i controlli di argv
void parse(int argc, char *argv)
{
	
}

//qua dentro ci  stanno le chiamate alle funzioni. prima parse
// poi creazione thread
int	main(int argc, char *argv[])
{
	int	i;
	int	conv;

	t_coders *codx = malloc(atoi(argv[1]) * sizeof(t_coders));
	// assegni variabili
	if (argc != 2)
		return (0);
	i = 0;
	conv = atoi(argv[1]);
	while(i < conv && conv > 0)
	{
		if (pthread_create(&codx[i].coder_thread, NULL, &coders, NULL) != 0)
		{
			printf("No threads created");
			return 1;
		}
		i++;
	}
	while(i < conv)
	{
		// qui ci va il pthread_join
	}
	return (0);
}
