# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: camilla <camilla@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/31 14:52:25 by cavivian          #+#    #+#              #
#    Updated: 2026/09/15 12:01:42 by camilla          ###   ########.fr        #
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
		

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME) 

re: fclean all


.PHONY: all clean fclean re
