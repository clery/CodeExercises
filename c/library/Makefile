CC		= gcc

CFLAGS	= -std=c99

NAME		= lib/libclery.a

SRC		= src/array.c

OBJ		= $(SRC:.c=.o)

all:		$(NAME)
		

$(NAME):	$(OBJ)
		ar rc $@ $^

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re