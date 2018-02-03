# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdumitra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/02 20:47:11 by tdumitra          #+#    #+#              #
#    Updated: 2018/02/02 21:14:11 by tdumitra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c matrices.c solver.c grid.c read_input.c tetro_checker.c

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

HEADER = -c -I fillit.h

all: $(NAME)

$(OBJ): %.o: %.c
		@gcc -c -Wall -Werror -Wextra -I /bft $< -o $@

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(OBJ) $(LIBFT) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft fclean

re: fclean all
