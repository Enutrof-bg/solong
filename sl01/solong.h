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
#define TILE_SIZE 65


typedef struct s_image
{
	void *img;
	char *imgdest;
	// char *addr;
	// int bits_per_pixels;
	// int line_length;
	// int endian;
	// int x;
	// int y;
	int width;
	int height;
}t_image;

typedef struct s_data
{
	void *mlx;
	void *mlx_win;
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

char	*ft_strdup(char *s);

#endif