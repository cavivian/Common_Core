/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:28:10 by cavivian          #+#    #+#             */
/*   Updated: 2026/01/21 11:48:16 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

void			ft_putchar(char c);
int				ft_putstr(char *str);
int				ft_putint(int n);
int				ft_puthexlow(unsigned long nb, char a);
int				ft_putnbr(int nb);
int				ft_puthexupp(unsigned int nb);
int				ft_putunsnbr(unsigned int nb);
int				ft_putnullpoint(void *c);
int				ft_printf(const char *format, ...);
size_t			ft_strlen(const char *str);
int				ft_itoa(long num);
int				count_intlen(long num);
void			*ft_calloc(size_t num, size_t size);
unsigned long	ft_countuns(unsigned long num);
int				ft_count(char a, va_list *ap);

#endif 