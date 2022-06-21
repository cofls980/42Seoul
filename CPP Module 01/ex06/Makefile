NAME = harlFilter
SRC = main.cpp Harl.cpp
OBJ = $(SRC:%.cpp=%.o)
INC = ./

CC = c++
CFLAGS = -Wall -Wextra -Werror 
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC)  -o $(NAME) $(OBJ)
#$(CFLAGS) $(CFLAGS)
%.o: %.cpp
	$(CC) -c -o $@ $< -std=c++98

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re