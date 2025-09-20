Name = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

Src = ft_calloc.c \
      ft_split.c \
      push_swap.c \
      ft_substr.c \
	  ft_strlen.c \
	  ft_strdup.c \
	  ft_atoi.c		\
	  ft_isdigit.c	\
	  operations.c	\
	  small_sort.c
Obj = $(Src:.c=.o)

all: $(Name)

$(Name): $(Obj)
	$(CC) $(CFLAGS) $(Obj) -o $(Name)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(Obj)

fclean: clean
	rm -f $(Name)

re: fclean all

.PHONY: all clean fclean re
