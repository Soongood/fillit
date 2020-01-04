# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baegon <baegon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/04 14:41:06 by baegon            #+#    #+#              #
#    Updated: 2020/01/04 15:39:08 by baegon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FUNCTIONS = checker converter error main open printer reader solver

O_FILES = $(addsuffix .o, $(FUNCTIONS))

LIB = ./libft/libft.a

LIBFT = libft

CFLAGS = -Wall -Wextra -Werror -I . -I $(LIBFT)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIB) $(O_FILES) ./libft/libft.a
	@gcc $^ $(LIBFT)/libft.a -o $@

$(LIB):		FORCE
	@make -C ./libft

FORCE:	;

%.o: %.c
	@gcc $(CFLAGS) -o $@ -c $<

clean:
	@/bin/rm -f $(addsuffix .o,$(FUNCTIONS))
	@make -C ./libft clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all
