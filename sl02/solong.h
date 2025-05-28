/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:30:34 by kevwang           #+#    #+#             */
/*   Updated: 2025/05/26 15:30:35 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H


#define HEIGHT 720
#define WIDTH 480
#define TILE_SIZE 64

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define KEY_ESC 65307

typedef struct s_image
{
	void *img_grass;
	char *dest_grass;
	void *img_wall;
	char *dest_wall;
	void *img_char;
	char *dest_char;
	void *img_key;
	char *dest_key;
	void *img_exit;
	char *dest_exit;
	void *img_exit_open;
	char *dest_exit_open;
	// char *addr;
	// int bits_per_pixels;
	// int line_length;
	// int endian;
	// int x;
	// int y;
	int width;
	int height;
}t_image;

typedef struct s_anim
{
	// void *img_anim1;
	// void *img_anim2;
	// void *img_anim3;
	// void *img_anim4;
	// void *img_anim5;
	// void *img_anim6;
	// void *img_anim7;
	// void *img_anim8;
	// char *dest_anim1;
	// char *dest_anim2;
	// char *dest_anim3;
	// char *dest_anim4;
	// char *dest_anim5;
	// char *dest_anim6;
	// char *dest_anim7;
	// char *dest_anim8;
	void *img_anim[8];
	char *dest_anim[8];
}t_anim;

// typedef struct s_map
// {
// 	int count_e;
// 	int count_p;
// 	int count_c;
// }t_map;

typedef struct s_data
{
	void *mlx;
	void *mlx_win;
	char **map;
	int count_e;
	int count_p;
	int count_c;
	int map_length;
	int map_height;
	int player_x;
	int player_y;
	int player_collect;
	int player_end;
	int exit_x;
	int exit_y;
	t_image	img;
	t_anim anim;
}t_data;


#include "gnl/get_next_line.h"

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <stdlib.h>
# include <time.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>

char	*ft_strdup(char *s);
char	**ft_split(char const *s, char c);
char **ft_open_map(t_data *data, char *filename);
void ft_map_check(t_data *data, char *filename);
char	*ft_itoa(int n);
int	ft_printf(const char *str, ...);

#endif