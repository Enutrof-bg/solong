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

FILE = solong.c solong_utils.c solong_free.c solong_init.c solong_move.c \
solong_print_img.c solong_print_img2.c solong_init_xpm.c solong_init_xpm2.c \
map_check.c map_check_compo.c map_check_free.c map_check_open.c map_check_path.c \
ft_split.c ft_itoa.c \
${DIRGNL}/get_next_line.c ${DIRGNL}/get_next_line_utils.c \
${DIRPRINT}/ft_printf.c ${DIRPRINT}/ft_putcharstr.c ${DIRPRINT}/ft_puthexa.c \
${DIRPRINT}/ft_putnbr.c ${DIRPRINT}/ft_putptr.c ${DIRPRINT}/ft_putunsigned.c

SRC = ${FILE:.c=.o}

NAME = so_long

# FILE2 = map_check.c solong_utils.c ft_split.c ft_itoa.c\
# ${DIRGNL}/get_next_line.c ${DIRGNL}/get_next_line_utils.c\
# ${DIRPRINT}/ft_printf.c ${DIRPRINT}/ft_putcharstr.c ${DIRPRINT}/ft_puthexa.c\
# ${DIRPRINT}/ft_putnbr.c ${DIRPRINT}/ft_putptr.c ${DIRPRINT}/ft_putunsigned.c
# MAPCHECK = ${FILE2:.c=.o}
# FILEGNL = ${DIRGNL}/get_next_line.c ${DIRGNL}/get_next_line_utils.c
# SRCGNL = ${FILEGNL:.c=${DIRGNL}.o}


# FILEPRINT = ${DIRPRINT}/ft_printf.c ${DIRPRINT}/ft_putcharstr.c ${DIRPRINT}/ft_puthexa.c\
# ${DIRPRINT}/ft_putnbr.c ${DIRPRINT}/ft_putptr.c ${DIRPRINT}/ft_putunsigned.c
# SRCPRINT = ${FILEPRINT:.c=${DIRPRINT}.o}

all: ${NAME}

# map: ${MAPCHECK}
# 	${CC} ${CFLAGS} $^ ${MLX} -o map

${NAME} : ${SRC}
	make -C minilibx-linux
	${CC} ${CFLAGS} $^ ${MLX} -o $@

%.o:%.c
	${CC} ${CFLAGS} -c $< -o $@

# %.o:%.c
# 	${CC} ${CFLAGS} -c $< -o $@

# ${DIRPRINT}%.o:%.c
# 	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f solong.o solong_utils.o solong_free.o solong_init.o solong_move.o \
	solong_print_img.o solong_print_img2.o solong_init_xpm.o solong_init_xpm2.o \
	map_check.o map_check_compo.o map_check_free.o map_check_open.o map_check_path.o \
	ft_split.o ft_itoa.o \
	${DIRGNL}/get_next_line.o ${DIRGNL}/get_next_line_utils.o \
	${DIRPRINT}/ft_printf.o ${DIRPRINT}/ft_putcharstr.o ${DIRPRINT}/ft_puthexa.o \
	${DIRPRINT}/ft_putnbr.o ${DIRPRINT}/ft_putptr.o ${DIRPRINT}/ft_putunsigned.o

fclean: clean
	rm -f so_long

re: fclean
	make