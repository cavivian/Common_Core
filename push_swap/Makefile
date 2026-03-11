# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: camilla <camilla@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/11 15:50:53 by cavivian          #+#    #+#              #
#    Updated: 2026/03/10 19:18:52 by camilla          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -c

SRCS = push_swap.c/
	moves.c /
	movep.c /
	

	
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
