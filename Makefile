# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 17:06:19 by tayeo             #+#    #+#              #
#    Updated: 2022/09/09 17:06:23 by tayeo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
	rm -f client
	make clean -C lib
	make clean -C libft

fclean: clean
	make fclean -C lib
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
