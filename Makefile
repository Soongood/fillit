FUNCTIONS = checker converter error main open printer reader solver

O_FILES = $(addsuffix .o, $(FUNCTIONS))

LIBFT = libft

CFLAGS = -Wall -Wextra -Werror -I . -I $(LIBFT)

NAME = fillit

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(O_FILES)
	cd ./libft && make
	gcc $^ $(LIBFT)/libft.a -o $@

%.o: %.c
	gcc $(CFLAGS) -o $@ -c $<

clean:
	@/bin/rm -f $(addsuffix .o,$(FUNCTIONS))
	cd ./libft && make clean

fclean: clean
	@/bin/rm -f $(NAME)
	cd ./libft && make fclean

re: fclean all
