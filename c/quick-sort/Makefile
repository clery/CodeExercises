CC		= gcc

CFLAGS	= -std=c99
CFLAGS	+= -I$(LIBRARY)/include

NAME		= sort

SRC		= main.c
SRC		+= sort.c

OBJ		= $(SRC:.c=.o)

LIBRARY	= ../library

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIBRARY)
		make -C $(LIBRARY) clean
		$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LIBRARY)/lib/libclery.a

clean:
	make -C $(LIBRARY) clean
	rm -f $(OBJ)

fclean:	clean
	make -C $(LIBRARY) fclean
	rm -f $(NAME)

re:	fclean all
	make -C $(LIBRARY) re

.PHONY: all clean fclean re