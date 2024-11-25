# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 16:18:59 by alde-abre         #+#    #+#              #
#    Updated: 2024/11/25 18:58:35 by alde-abre        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line
CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

#Def du chemin d'acces des fichiers sources
SRC = $(wildcard *.c)

#Création des fichiers .o
OBJ = $(SRC:.c=.o)

#Compilation de la lib
$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

#Compilation des fichiers .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
