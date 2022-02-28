NAME = push_swap
SRC_FILES = main.c\
			commands.c\
			dll.c\
			free.c\
			ft_split.c\
			number.c\
			push_swap.c\
			sort_stack.c\
			sort_under_five.c\
			sort_under_three.c\
			check.c
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_BONUS = $(BONUS_FILES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#$(NAME): $(OBJ_FILES)
#$(AR) $@ $^
$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJ_FILES) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
