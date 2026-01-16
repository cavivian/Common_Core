# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/11 15:50:53 by cavivian          #+#    #+#              #
#    Updated: 2026/01/16 11:51:03 by cavivian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -c

SRCS = 	ft_external_func.c \
	ft_exfunct.c \
	ft_count.c \
	ft_printf.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

$(OBJS):
		cc $(CFLAGS) $(SRCS)

clean:
	rm -f $(OBJS)
	@echo "File oggetto rimossi."

fclean: clean
	rm -f $(NAME)
	@echo "Tutto pulito (eseguibile eliminato)."

re: fclean all

.PHONY: all clean fclean re