# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aarts <aarts@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 19:42:27 by aarts             #+#    #+#              #
#    Updated: 2022/03/09 17:46:10 by aarts            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I

SRC =	ft_printf.c				\
		ft_printf_utils.c		\
		ft_printf_moreutils.c	\
		
OBJ = $(SRC:.c=.o)

$(NAME):
		@$(CC) $(CFLAGS) -c $(SRC)
		@ar rcs $(NAME) $(OBJ)

all:	$(NAME)

clean:
		@rm -f $(OBJ)

fclean:	clean
		@rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re bonus