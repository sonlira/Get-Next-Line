# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 13:38:00 by abaldelo          #+#    #+#              #
#    Updated: 2024/10/15 13:55:10 by abaldelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= get_next_line.a
RM		= rm -f
CC		= cc
FLAGS	= -Werror -Wextra -Wall
LIB		= ar r
SRC		= get_next_line.c

OBJ		= $(SRC: .c = .o)

all: $(NAME)

$(NAME): $(SRC)
			@$(CC) $(FLAGS) $(SRC) -c
			@$(LIB) $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME) $(OBJ)

re: clean fclean all

.PHONY: all fclean clean re