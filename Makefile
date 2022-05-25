NAME = minishell
SRC = main.c ft_split.c find_path.c\
	utils.c ft_echo.c list.c ft_env.c ft_export.c equal_parsing.c\
	pipes_parsing.c words_parsing.c ft_pwd.c command.c ft_unset.c\
	quote_var_parsing.c later.c init.c change_word.c
OBJ = $(SRC:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = ./includes
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lreadline

%.o: %.c
	$(CC) -c -o $@ $<
# $(CFLAGS) -I$(HEADER)
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re