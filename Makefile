#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fblom <marvin@codam.nl>                      +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/16 10:01:54 by fblom         #+#    #+#                  #
#    Updated: 2019/03/16 10:03:24 by fblom         ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = alum1

SRCS = main.c error_handling.c get_data.c put_board.c play_game.c colours.c \
		printers.c

FLAGS = -Wall -Werror -Wextra

LIB = libft/libft.a

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -o $(NAME) $(FLAGS) $(SRCS) $(LIB)

clean:
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
	make -C libft/ re
