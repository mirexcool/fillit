# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/13 16:51:50 by dburtnja          #+#    #+#              #
#    Updated: 2016/12/22 18:25:08 by dburtnja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -o
SRC =	main.c\
		libft.a\
		ft_fillit.c\
		make_arrays.c\
		ft_mkarray.c\
		move_tet.c\
		collection_tet.c\
		ft_check_tetr.c

all: $(NAME)
$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(NAME) $(SRC)

fclean:
	@rm -f $(NAME)

re:
	make fclean
	make all
