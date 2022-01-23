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

NAME = libft.a
SRC_FILES = ft_memset.c \
			ft_bzero.c \
	    	ft_memcpy.c \
	    	ft_memccpy.c \
	    	ft_memmove.c \
	    	ft_memchr.c \
	    	ft_memcmp.c \
	    	ft_strlen.c \
	    	ft_strlcpy.c \
	    	ft_strlcat.c \
	    	ft_strchr.c \
	    	ft_strrchr.c\
	    	ft_strnstr.c\
	    	ft_strncmp.c\
	    	ft_atoi.c\
	    	ft_isalpha.c\
	    	ft_isdigit.c\
	    	ft_isalnum.c\
	    	ft_isascii.c\
	    	ft_isprint.c\
	    	ft_toupper.c\
	    	ft_tolower.c\
	    	ft_calloc.c\
	    	ft_strdup.c\
	    	ft_substr.c\
	    	ft_strjoin.c\
	    	ft_strtrim.c\
	    	ft_split.c\
	    	ft_itoa.c\
	    	ft_strmapi.c\
	    	ft_putchar_fd.c\
	    	ft_putstr_fd.c\
	    	ft_putendl_fd.c\
	    	ft_putnbr_fd.c
BONUS_FILES = ft_lstnew.c\
			  ft_lstadd_front.c\
	      	  ft_lstsize.c\
	      	  ft_lstlast.c\
	      	  ft_lstadd_back.c\
	      	  ft_lstdelone.c\
	      	  ft_lstclear.c\
	      	  ft_lstiter.c\
	      	  ft_lstmap.c
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

bonus: $(OBJ_BONUS)
	$(AR) $(NAME) $^

.PHONY:	all clean fclean re bonus
