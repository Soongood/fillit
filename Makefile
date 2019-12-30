NAME	= fillit

FUNCTIONS = checker converter error main open printer reader solver

O_FILES = $(addsuffix .o, $(FUNCTIONS))

IDIR = .
SDIR = .
ODIR = obj
LIBFT = libft

CFLAGS = -Wall -Wextra -Werror -I $(DIR) -I $(LIBFT)

NAME = fillit

DEPS = $(IDIR)/fillit.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(O_FILES) $(LIBFT)/libft.a
	gcc $^ $(LIBFT)/libft.a -o $@

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@mkdir -p $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	@/bin/rm -f $(addsuffix .o,$(FUNCTIONS))

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
