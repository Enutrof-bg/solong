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

SRC = ${FILE:.c=.o}

NAME = so_long

FILEBONUS = solong_bonus.c solong_utils.c solong_free_bonus.c solong_init_bonus.c solong_move_bonus.c solong_move_ennemy_bonus.c\
solong_print_img.c solong_print_img2.c solong_init_xpm.c solong_init_xpm2.c solong_init_xpm_bonus.c solong_anim.c \
solong_init_xpm_key_bonus.c solong_init_xpm_char_bonus.c \
solong_print_ennemy_bonus.c solong_move_ennemy_mort_bonus.c \
map_check.c map_check_compo.c map_check_free.c map_check_open.c map_check_path.c \
ft_split.c ft_itoa.c \
${DIRGNL}/get_next_line.c ${DIRGNL}/get_next_line_utils.c \

NAMEBONUS = so_long_bonus

SRCBONUS = ${FILEBONUS:.c=.o}

FILEPRINTF = ${DIRPRINT}/ft_printf.o ${DIRPRINT}/ft_putcharstr.o ${DIRPRINT}/ft_puthexa.o \
${DIRPRINT}/ft_putnbr.o ${DIRPRINT}/ft_putptr.o ${DIRPRINT}/ft_putunsigned.o

all: ${NAME}

${NAME} : ${SRC} ${FILEPRINTF}
	make -C minilibx-linux
	make -C ft_printf
	${CC} ${CFLAGS} $^ ${MLX} -o $@

%.o:%.c
	${CC} ${CFLAGS} -c $< -o $@

bonus: ${NAMEBONUS}

${NAMEBONUS} : ${SRCBONUS} ${FILEPRINTF}
	make -C minilibx-linux
	make -C ft_printf
	${CC} ${CFLAGS} $^ ${MLX} -o so_long_bonus

${BONUS}:

clean:
	rm -f solong.o solong_utils.o solong_free.o solong_init.o solong_move.o \
	solong_print_img.o solong_print_img2.o solong_init_xpm.o solong_init_xpm2.o \
	map_check.o map_check_compo.o map_check_free.o map_check_open.o map_check_path.o \
	ft_split.o ft_itoa.o \
	${DIRGNL}/get_next_line.o ${DIRGNL}/get_next_line_utils.o \
	solong_move_bonus.o solong_move_ennemy_bonus.o solong_init_xpm_bonus.o \
	solong_print_ennemy_bonus.o solong_init_bonus.o solong_move_ennemy_mort_bonus.o solong_anim.o \
	solong_init_xpm_key_bonus.o solong_init_xpm_char_bonus.o solong_free_bonus.o solong_bonus.o
	make fclean -C ft_printf

fclean: clean
	rm -f so_long
	rm -f so_long_bonus

re: fclean
	make