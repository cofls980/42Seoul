NAME= so_long
SRC = src/main.c src/move.c src/map.c src/image.c
OBJ = $(SRC:%.c=%.o)

MLX_DIR = ./minilibx-linux
LFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

RM = rm -f
CC = gcc
#CFLAGS = -Wall -Wextra -Werror
HEADER = ./includes

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

%.o: %.c
	$(CC) -I$(MLX_DIR) -I$(HEADER) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJ_BONUS)
	$(CC) $(CFLAGS) -o $(NAME) $^

.PHONY: all clean fclean re bonus