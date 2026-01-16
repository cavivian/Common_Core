/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:28:10 by cavivian          #+#    #+#             */
/*   Updated: 2026/01/16 14:16:56 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_putint(int n);
int		ft_putper(void);
int		ft_puthexlow(unsigned int nb);
void	ft_putnbr(int nb);
int		ft_puthexupp(unsigned int nb);
int		ft_putunsnbr(unsigned int nb);
int		ft_putnullpoint(void *c);
int		ft_count(int i);
char	*ft_itoahex(long num);
char	ft_conv(int b);
int		ft_perc(char c, va_list args);
int		ft_printf(const char *format, ...);

#endif 