/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:33:08 by cavivian          #+#    #+#             */
/*   Updated: 2026/01/16 13:17:48 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int fd)
{
	write (1, &c, 1);
}

/*int main()
{
	int fd = open ("file.txt", O_WRONLY);
	ft_putchar_fd('a', fd);
}*/
