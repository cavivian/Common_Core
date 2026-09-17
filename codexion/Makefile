# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/31 14:52:25 by cavivian          #+#    #+#              #
#    Updated: 2026/09/17 17:26:00 by cavivian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = codexion

CC = cc

CFLAGS = -Wall -Wextra -Werror -pthread

SRCS = codexion.c \
	init_thread_and_mutex.c \
	error_management.c \
	dongle.c \
	monitor.c \
	actions.c \
	monitor_error_management.c \
	prints_messages.c \
	algorithms.c \
	heap.c \
		

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME) 

re: fclean all


.PHONY: all clean fclean re
