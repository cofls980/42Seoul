NAME = pipex
#LIBFT = Libft/libft.a
SRC_FILES = pipex.c find_path.c utils.c ft_split.c
BONUS_FILES = pipex_bonus.c
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_BONUS = $(BONUS_FILES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES) #$(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ 
#$(LIBFT)

#$(LIBFT):
#	make -C Libft

clean:
	$(RM) $(OBJ_FILES) $(OBJ_BONUS)
#make clean -C Libft

fclean: clean
	$(RM) $(NAME)
#make fclean -C Libft

re: fclean all

bonus: $(OBJ_BONUS)
	$(CC) $(NAME) $^

.PHONY:	all clean fclean re bonus
