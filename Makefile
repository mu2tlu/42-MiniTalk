# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mumutlu <mumutlu@student.42kocaeli.com.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 17:06:40 by mumutlu           #+#    #+#              #
#    Updated: 2023/04/28 17:06:41 by mumutlu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMESERVER = server
NAMECLIENT = client
LIB = ./ft_printf/libftprintf.a
SRCSERVER = server.c
SRCCLIENT = client.c
FLAGS = -Wall -Wextra -Werror
CC = gcc
OBJSERVER = $(SRCSERVER:.c=.o)
OBJCLIENT = $(SRCCLIENT:.c=.o)

all: $(LIB) $(NAMESERVER) $(NAMECLIENT)

$(LIB):
	make -C ./ft_printf

$(NAMESERVER) : $(OBJSERVER)
	$(CC) $(OBJSERVER) -o $(NAMESERVER) $(LIB)

$(NAMECLIENT) : $(OBJCLIENT)
	$(CC) $(OBJCLIENT) -o $(NAMECLIENT) $(LIB)

clean:
	rm -rf $(OBJSERVER) $(OBJCLIENT)

fclean: clean
	rm -rf $(NAMESERVER) $(NAMECLIENT)

ffclean: fclean
	make fclean -C ./ft_printf

.c.o:
	$(CC) $(FLAGS) -c $^ -o $@

norm:
	norminette *.[ch]

re:fclean all

.PHONY : re fclean clean all ffclean norm


/*

NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror
LIBFTPRİNTF = ft_printf

all: $(NAME)
		gcc $(FLAG) server.c $(NAME) -o server
		gcc $(FLAG) client.c $(NAME) -o client
$(NAME): $(LIBFTPRİNTF)
		make -C $(LIBFTPRİNTF)
		cp ft_printf/libftprintf.a .
clean:
		make clean -C $(LIBFTPRİNTF)
		rm -rf server.o client.o
		rm -rf server client
fclean: clean
		make fclean -C $(LIBFTPRİNTF)
		rm -rf $(NAME)
		rm -rf server client

re: fclean all

.PHONY: clean fclean re

*/
