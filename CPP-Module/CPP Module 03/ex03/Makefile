NAME = diamond
SRC = main.cpp ClapTrap.cpp DiamondTrap.cpp FragTrap.cpp ScavTrap.cpp
OBJ = $(SRC:%.cpp=%.o)
INC = ./

CXX = c++
CXXFLAGS = -Wshadow -Wall -Wextra -Werror -std=c++98
RM = rm -rf
# -Wno-shadow
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