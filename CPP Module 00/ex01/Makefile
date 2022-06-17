NAME = phonebook
SRC = main.cpp Contact.cpp PhoneBook.cpp
OBJ = $(SRC:%.cpp=%.o)
INC = ./

CC = c++
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $< -std=c++98

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re