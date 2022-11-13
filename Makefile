NAME = containers
SRC = map_test.cpp
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
ifeq ($(mode), ft_mode)
	$(CXX) $(CXXFLAGS) -DFT_MODE -c -o $@ $<
else
	$(CXX) $(CXXFLAGS) -c -o $@ $<
endif
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

# make mode=ft_mode