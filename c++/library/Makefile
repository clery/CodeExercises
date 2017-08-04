NAME = test

SRC = src/vertex.cpp

OBJ = $(SRC:.cpp=.o)

CXX = g++

CXXFLAGS = -I ./include

all:	$(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean fclean all

.PHONY: all clean fclean re
