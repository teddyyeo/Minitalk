# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 14:57:30 by tayeo             #+#    #+#              #
#    Updated: 2022/08/25 18:18:53 by tayeo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC=ft_printf.c format_str_parser.c put_uint.c put_hex.c basic_utils.c ft_putnbr.c

OBJ = ${SRC:.c=.o}
FLAG = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar -r $@ $?
	ranlib $(NAME)

%.o: %.c
	gcc -c $(FLAG) $?

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
