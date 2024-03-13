CC = gcc

CFLAGS = -g -Wall -Wextra

NAME = server

NAME2 = client

SRCS = server.c

SRCS2 = client.c

OBJ = $(SRCS:.c=.o)

OBJ2 = $(SRCS2:.c=.o)

all     :   $(NAME)

$(NAME) :   $(OBJ) $(OBJ2)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./libft/ -lft
	$(CC) $(CFLAGS) $(OBJ2) -o $(NAME2) -L./libft/ -lft
clean   :
	$(MAKE) -C libft clean
	rm -rf $(OBJ)
	rm -rf $(OBJ2)
fclean  :   clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)
	rm -f $(NAME2)

re      :   fclean all

.PHONY  :   clean fclean all re
