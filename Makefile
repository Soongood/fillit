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

LIBFT = ./libft/libft.a

CFLAGS = -Wall -Wextra -Werror -I . -I $(LIBFT)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(O_FILES) $(LIBFT)
	gcc $^ -o $@

$(LIBFT)::
	make -C ./libft

%.o: %.c
	gcc $(CFLAGS) -o $@ -c $<

clean:
	/bin/rm -f $(O_FILES)
	make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./libft fclean

re: fclean all
