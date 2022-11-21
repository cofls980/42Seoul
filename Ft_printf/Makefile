NAME = libftprintf.a
SRC_FILES = ft_printf.c\
			ft_write.c\
			ft_number.c\
			ft_addr.c
BONUS_FILES = ft_printf_bonus.c
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_BONUS = $(BONUS_FILES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES)
	$(AR) $@ $^

clean:
	$(RM) $(OBJ_FILES) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJ_FILES)
	$(AR) $(NAME) $^

.PHONY: all clean fclean re
