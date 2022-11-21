NAME = philo
SRC = main.c end.c error.c init.c monitor.c\
		print.c routine.c utils.c thread.c
OBJ = $(SRC:%.c=%.o)

RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = ./includes
PFLAGS = -pthread

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(PFLAGS) -o $(NAME) $(OBJ) -g -fsanitize=thread

%.o: %.c
	$(CC) $(CFLAGS) $(PFLAGS) -I$(HEADER) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re