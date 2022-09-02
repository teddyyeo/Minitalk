
NAME1 = server

NAME2 = client

FLAG = -Werror -Wall -Wextra

LIB = lib/libftprintf.a
LIBFT = libft/libft.a

all: $(NAME1) $(NAME2)

$(NAME1): server.c $(LIB) $(LIBFT)
	gcc $(FLAG) $^ -o $(NAME1)

$(NAME2): client.c $(LIB) $(LIBFT)
	gcc $(FLAG) $^ -o $(NAME2)

$(LIB):
	make -C lib

$(LIBFT):
	make -C libft
clean:
	rm -f server
	make clean -C lib
	make clean -C libft

fclean: clean
	rm -f server
	make fclean -C lib
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
