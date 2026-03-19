/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:13:10 by cavivian          #+#    #+#             */
/*   Updated: 2026/03/18 10:52:55 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	easyswap(int argc, struct Stacks *a_b)
{
	if (!argc || !a_b)
		return (NULL);
	if (argc <= 5)
		sort_check(a_b);
	if (!sort_check(a_b) && argc <= 5)
		sort(argc, a_b);
}

int	push_swap(struct Stacks *aabb, int *argc, char *argv)
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

int	main( int argc, char *argv[])
{
    printf("Number of arguments: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
    return 0;
}
