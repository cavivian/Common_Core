/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:21 by cavivian          #+#    #+#             */
/*   Updated: 2026/08/14 16:15:46 by camilla          ###   ########.fr       */
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

struct controllo
{
    pthread_t time_to_burnout;
    pthread_t number_of_compiles_required;
};

struct Coders
{
    pthread_t numbers_of_coders;
    pthread_t time_to_compile;
    pthread_t time_to_debug;
    pthread_t time_to_refactor;
    
};



#endif