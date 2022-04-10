NAME = pipex
SRC_FILES = src/main.c src/pipex.c src/find_path.c src/utils.c src/ft_split.c src/strings.c src/get_next_line.c
BONUS_FILES = src_bonus/main_bonus.c src_bonus/pipex_bonus.c src_bonus/find_path_bonus.c src_bonus/utils_bonus.c src_bonus/ft_split_bonus.c src_bonus/strings_bonus.c src_bonus/get_next_line_bonus.c
HDR = -I ./includes
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_BONUS = $(BONUS_FILES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(HDR) -c $< -o $@

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJ_FILES) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJ_BONUS)
	$(CC) $(CFLAGS) -o $(NAME) $^

.PHONY:	all clean fclean re bonus
