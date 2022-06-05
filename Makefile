NAME = minishell
SRC = main.c ft_split.c find_path.c utils.c list.c signal.c init.c ft_utils.c\
	command/ft_echo.c command/ft_env.c command/ft_export.c\
	command/ft_pwd.c command/command.c command/ft_unset.c command/execute.c\
	command/ft_cd.c command/ft_exit.c command/ft_utils.c\
	parsing/pipes_parsing.c parsing/words_parsing.c parsing/equal_parsing.c\
	parsing/quote_var_parsing.c parsing/word_change.c parsing/redirect_parsing.c\
	parsing/word_len.c parsing/here_doc.c parsing/parsing_utils.c
#parsing/get_next_line.c
OBJ = $(SRC:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = ./includes
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(shell brew --prefix readline)/lib/ -lreadline
%.o: %.c
	$(CC) $(CFLAGS) -I$(HEADER) -c -o $@ $< -I$(shell brew --prefix readline)/include/
# -I lib/libft/include/ 
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re