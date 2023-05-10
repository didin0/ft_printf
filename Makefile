# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabbadi <mabbadi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 16:00:48 by mabbadi           #+#    #+#              #
#    Updated: 2023/05/10 12:41:19 by mabbadi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = srcs/ft_printf.c srcs/ft_printhex.c srcs/ft_printnbr.c srcs/ft_printpercent.c srcs/ft_printptr.c srcs/ft_printstr.c srcs/ft_printunsigned.c \

FLAGS = -Wall -Wextra -Werror

OBJ = ${SRC:.c=.o}

${NAME}: ${OBJ}
		@ar rc ${NAME} ${OBJ}
		@make -C libft

all: ${NAME}

%.o: %.c
		cc ${FLAGS} -I ./ -c $< -o ${<:.c=.o}

clean:
		@rm -rf ${OBJ}
		@make clean -C libft

fclean: clean
		@rm -rf ${NAME}
		@make fclean -C libft

re: fclean all

.PHONY: all re clean fclean