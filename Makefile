Name = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

Src = src/push_swap.c \
	  src/push.c \
	  src/swap.c \
	  src/rotate.c \
	  src/reverse_rotate.c \
	  src/small_sort.c \
	  src/radix_indexing.c \
	  src/radix_sort.c \
	  src/checkers.c \
	  src/utils.c \
	  src/parsing.c \

Libftdir = libft
Libftname = $(Libftdir)/libft.a

Obj = $(Src:.c=.o)

all: $(Name)

$(Libftname):
	make -C $(Libftdir)

$(Name): $(Obj) $(Libftname)
	$(CC) $(CFLAGS) $(Obj) $(Libftname) -o $(Name)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(Libftdir)
	rm -f $(Obj)

fclean: clean
	make fclean -C $(Libftdir)
	rm -f $(Name) $(Obj)

re: fclean all

.PHONY: all clean fclean re
