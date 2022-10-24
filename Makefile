NAME = containers
SRC = test1.cpp
OBJ = $(SRC:%.cpp=%.o)
INC = ./

CXX = c++
CXXFLAGS =  -std=c++98 -Wall -Wextra -Werror
RM = rm -rf
#-Wall -Wextra -Werror -DDEBUG_MODE -Wundef
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re