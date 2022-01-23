# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chaekim <chaekim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/10 16:42:49 by chaekim           #+#    #+#              #
#    Updated: 2021/06/10 16:42:51 by chaekim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
LIBFT = Libft/libft.a
SRC_FILES = pipex.c
BONUS_FILES = pipex_bonus.c
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_BONUS = $(BONUS_FILES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

$(LIBFT):
	make -C Libft

clean:
	$(RM) $(OBJ_FILES) $(OBJ_BONUS)
	make clean -C Libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C Libft

re: fclean all

bonus: $(OBJ_BONUS)
	$(CC) $(NAME) $^

.PHONY:	all clean fclean re bonus
