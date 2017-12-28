# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yazhu <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/02 16:09:18 by yazhu             #+#    #+#              #
#    Updated: 2017/12/07 14:39:18 by yazhu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit
SRCS	= srcs/backward.c srcs/exit_with_error.c srcs/fill_board.c srcs/format_blocks.c srcs/main.c srcs/solve.c
OFILES	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	cd libft && make
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRCS) -L ./libft -lft

clean:
	cd libft && make clean
	/bin/rm -f $(OFILES)

fclean: clean
	cd libft && make fclean
	/bin/rm -f $(NAME)

re: fclean all
