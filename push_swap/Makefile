# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/11 15:50:53 by cavivian          #+#    #+#              #
#    Updated: 2026/04/01 08:59:00 by cavivian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS =	push_swap.c \
	moves.c \
	movepr.c \
	mover.c \
	sorting.c \
	sortutils.c \
	chunk.c \
	chunkutils.c \
	ft_atoi.c \
	parse.c \
	utils.c \
	utilisation.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

#$(OBJS): 
#		$(CC) $(CFLAGS) $(SRCS)

clean:
	rm -f $(OBJS)
	@echo "File oggetto rimossi."
	
fclean: clean
	rm -f $(NAME)
	@echo "Tutto pulito (eseguibile eliminato)."
	
re: fclean all

.PHONY: all clean fclean re
