# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chaekim <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 04:02:17 by chaekim           #+#    #+#              #
#    Updated: 2022/01/25 04:02:19 by chaekim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
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

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ 

clean:
	$(RM) $(OBJ_FILES) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJ_BONUS)
	$(CC) $(NAME) $^

.PHONY:	all clean fclean re bonus
