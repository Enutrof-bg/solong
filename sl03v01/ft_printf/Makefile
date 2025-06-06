# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/02 12:27:30 by kevwang           #+#    #+#              #
#    Updated: 2025/05/02 12:27:31 by kevwang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_putcharstr.c ft_puthexa.c ft_putnbr.c ft_putptr.c ft_putunsigned.c

OBJ = ${SRC:.c=.o}

NAME = libftprintf.a

all : ${NAME}

${NAME} : ${OBJ}
	ar -rcs -o $@ $^

%.o:%.c
	${CC} ${CFLAGS} -c $^

clean :
	rm -f ft_printf.o ft_putcharstr.o ft_puthexa.o ft_putnbr.o ft_putptr.o ft_putunsigned.o

fclean : clean
	rm -f libftprintf.a

re : fclean
	make
