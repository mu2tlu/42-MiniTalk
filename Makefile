# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mumutlu <mumutlu@student.42kocaeli.com.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 15:17:29 by mumutlu           #+#    #+#              #
#    Updated: 2023/05/27 15:17:36 by mumutlu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror
LIBFTPRİNTF = ft_printf

all: $(NAME)
		gcc $(FLAG) server.c $(NAME) -o server
		gcc $(FLAG) client.c $(NAME) -o client
bonus: $(NAME)
		gcc $(FLAG) server_bonus.c $(NAME) -o server_bonus
		gcc $(FLAG) client_bonus.c $(NAME) -o client_bonus
$(NAME): $(LIBFTPRİNTF)
		make -C $(LIBFTPRİNTF)
		cp ft_printf/libftprintf.a .
clean:
		make clean -C $(LIBFTPRİNTF)
		rm -rf server.o client.o server_bonus.o client_bonus.o
		rm -rf server client server_bonus client_bonus

fclean: clean
		make fclean -C $(LIBFTPRİNTF)
		rm -rf $(NAME)
		rm -rf server client server_bonus client_bonus

re: fclean all

.PHONY: clean fclean re bonus
