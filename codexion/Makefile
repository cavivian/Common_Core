# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/31 14:52:25 by cavivian          #+#    #+#              #
#    Updated: 2026/07/31 15:00:38 by cavivian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = codexion

CC = cc

CFLAGS = -Wall -Wextra -Werror 

SRCS = codexion.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re
