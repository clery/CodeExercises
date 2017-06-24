NAME		= lib/libclery.so

SRC		= src/array.c

OBJ		= $(SRC:.c=.o)

CFLAGS	= -std=c99 -fPIC

CC		= gcc

$(NAME):	all

all:		$(OBJ)
		$(CC) -shared $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re