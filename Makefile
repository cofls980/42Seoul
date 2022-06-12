NAME = minishell
SRC = main.c ft_split.c find_path.c utils.c list.c ft_signal.c init.c\
	ft_utils.c list_insert.c ft_strutils.c utils2.c\
	check_syntax.c command/ft_echo.c command/ft_env.c command/ft_export.c command/ft_export2.c\
	command/ft_pwd.c command/command.c command/ft_unset.c\
	command/ft_cd.c command/ft_exit.c command/command_utils.c\
	parsing/pipes_parsing.c parsing/words_parsing.c parsing/equal_parsing.c\
	parsing/interpret_word.c parsing/get_interpret_word.c parsing/redirect_parsing.c parsing/redirect_parsing2.c\
	parsing/get_word_len.c parsing/here_doc.c parsing/parsing_utils.c parsing/parsing_utils2.c
OBJ = $(SRC:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = ./includes
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lreadline -g -fsanitize=address
# -L $(shell brew --prefix readline)/lib/
%.o: %.c
	$(CC) $(CFLAGS) -I$(HEADER) -c -o $@ $<
# -I lib/libft/include/  -I$(shell brew --prefix readline)/include/
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re