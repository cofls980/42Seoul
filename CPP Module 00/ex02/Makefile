NAME = account
SRC = tests.cpp Account.cpp
OBJ = $(SRC:%.cpp=%.o)
INC = ./

CC = c++
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) -c -o $@ $< -std=c++98

# $(CFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re