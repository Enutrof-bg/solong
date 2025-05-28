# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 15:30:29 by kevwang           #+#    #+#              #
#    Updated: 2025/05/26 15:30:30 by kevwang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX = -Lminilibx-linux -lmlx -lX11 -lXext
DIRGNL = gnl
DIRPRINT = ft_printf

FILE = solong.c solong_utils.c map_check.c ft_split.c ft_itoa.c\
${DIRGNL}/get_next_line.c ${DIRGNL}/get_next_line_utils.c\
${DIRPRINT}/ft_printf.c ${DIRPRINT}/ft_putcharstr.c ${DIRPRINT}/ft_puthexa.c\
${DIRPRINT}/ft_putnbr.c ${DIRPRINT}/ft_putptr.c ${DIRPRINT}/ft_putunsigned.c

SRC = ${FILE:.c=.o}


FILE2 = map_check.c solong_utils.c ft_split.c ft_itoa.c\
${DIRGNL}/get_next_line.c ${DIRGNL}/get_next_line_utils.c\
${DIRPRINT}/ft_printf.c ${DIRPRINT}/ft_putcharstr.c ${DIRPRINT}/ft_puthexa.c\
${DIRPRINT}/ft_putnbr.c ${DIRPRINT}/ft_putptr.c ${DIRPRINT}/ft_putunsigned.c
MAPCHECK = ${FILE2:.c=.o}
# FILEGNL = ${DIRGNL}/get_next_line.c ${DIRGNL}/get_next_line_utils.c
# SRCGNL = ${FILEGNL:.c=${DIRGNL}.o}


# FILEPRINT = ${DIRPRINT}/ft_printf.c ${DIRPRINT}/ft_putcharstr.c ${DIRPRINT}/ft_puthexa.c\
# ${DIRPRINT}/ft_putnbr.c ${DIRPRINT}/ft_putptr.c ${DIRPRINT}/ft_putunsigned.c
# SRCPRINT = ${FILEPRINT:.c=${DIRPRINT}.o}

all: solong

map: ${MAPCHECK}
	${CC} ${CFLAGS} $^ ${MLX} -o map

solong: ${SRC}
	${CC} ${CFLAGS} $^ ${MLX} -o so_long

%.o:%.c
	${CC} ${CFLAGS} -c $< -o $@

# %.o:%.c
# 	${CC} ${CFLAGS} -c $< -o $@

# ${DIRPRINT}%.o:%.c
# 	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f solong.o solong_utils.o map_check.o ft_split.o ft_itoa.o \
	gnl/get_next_line.o gnl/get_next_line_utils.o\
	ft_printf/ft_printf.o ft_printf/ft_putcharstr.o ft_printf/ft_puthexa.o\
	ft_printf/ft_putnbr.o ft_printf/ft_putptr.o ft_printf/ft_putunsigned.o

fclean: clean
	rm -f solong

re: fclean
	make