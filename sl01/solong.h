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


typedef struct s_image
{
	void *img_grass;
	char *dest_grass;
	void *img_wall;
	char *dest_wall;
	void *img_char;
	char *dest_char;
	// char *addr;
	// int bits_per_pixels;
	// int line_length;
	// int endian;
	// int x;
	// int y;
	int width;
	int height;
}t_image;

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
	t_image	img;
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

#endif