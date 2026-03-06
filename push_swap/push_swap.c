/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:13:10 by cavivian          #+#    #+#             */
/*   Updated: 2026/03/06 12:10:24 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int push_swap(struct Stacks, int *argc, char *argv)
{
	int	i;
	int	conversion;
	
	i = 1;
	while (i < argc)
	{
		conversion = ft_atoi(argv);
		i++;
	}

}
int main(int *argc[], char *argv[])
{
	if (argc <= 0 || !argv)
		write(1, "Error", sizeof(char));
	if (argc <= 5)
		easyswap();	
}

