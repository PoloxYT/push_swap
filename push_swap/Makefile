NAME = push_swap.a
SOURCES = ft_disorder_adaptative.c ft_push.c ft_reverse_rotate.c ft_rotate.c ft_swap.c ft_tri_par_selection.c ft_libft.c push_swap.c ft_tri_par_chunk.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	cc -Wall -Wextra -Werror -c $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all