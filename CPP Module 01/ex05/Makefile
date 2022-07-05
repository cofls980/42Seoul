NAME = harl
SRC = main.cpp Harl.cpp
OBJ = $(SRC:%.cpp=%.o)
INC = ./

CC = c++
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -std=c++98

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $< -std=c++98

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re