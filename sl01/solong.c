/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:30:37 by kevwang           #+#    #+#             */
/*   Updated: 2025/05/26 15:30:38 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
//caca solong.c -Lminilibx-linux -lmlx -lX11 -lXext
//caca solong.c gnl/get_next_line.c gnl/get_next_line_utils.c solong_utils.c ft_split.c -Lminilibx-linux -lmlx -lX11 -lXext

int on_destroy(t_data *data)
{

	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key:%d\n", keysym);
	// mlx_string_put(data->mlx, data->mlx_win, HEIGHT * 0.1, WIDTH * 0.1, 0x00FF0000, "keysym");
	return (0);
}

void	print_img_grass(t_data *data, t_image *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, img->img_grass,
		img->width * x, img->height * y);
}

void	print_img_wall(t_data *data, t_image *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, img->img_wall,
		img->width * x, img->height * y);
}

void	print_img_char(t_data *data, t_image *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, img->img_char,
		img->width * x, img->height * y);
}

// void	print_img(t_data *data, t_image *img, int x, int y)
// {
// 	int i = 0;
// 	int j = 0;
// 	while (i < 10)
// 	{
// 		while (j < 10)
// 		{
// 			mlx_put_image_to_window(data->mlx, data->mlx_win, img->img,
// 			img->width * x, img->height * y);
// 			j++;
// 		}
// 		j = 0;
// 		i++;
// 	}
	
// }

void set_img(t_data *data)
{
	data->img.width = 64;
	data->img.height = 64;
	data->img.dest_grass = "./sproutxpm/Sol.xpm";
	data->img.img_grass = mlx_xpm_file_to_image(data->mlx, data->img.dest_grass, &data->img.width, &data->img.height);
	if (!data->img.img_grass)
	{
	    printf("Erreur: Impossible de charger l'image XPM\n");
	    exit(EXIT_FAILURE);
	}

	data->img.dest_wall = "./sproutxpm/wall.xpm";
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx, data->img.dest_wall, &data->img.width, &data->img.height);
	if (!data->img.img_wall)
	{
	    printf("Erreur: Impossible de charger l'image XPM\n");
	    exit(EXIT_FAILURE);
	}

	data->img.dest_char = "./sproutxpm/char.xpm";
	data->img.img_char = mlx_xpm_file_to_image(data->mlx, data->img.dest_char, &data->img.width, &data->img.height);
	if (!data->img.img_char)
	{
	    printf("Erreur: Impossible de charger l'image XPM\n");
	    exit(EXIT_FAILURE);
	}
}

void ft_printf_map(t_data *data)
{
	int i = 0;
	int j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
				print_img_grass(data, &data->img, j, i);
			if (data->map[i][j] == '1')
				print_img_wall(data, &data->img, j, i);
			if (data->map[i][j] == 'P')
				print_img_char(data, &data->img, j, i);
			j++;
		}
		j = 0;
		i++;
	}
}

int main()
{
	t_data	data;

	ft_map_check(&data, "maps.ber");

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.mlx_win = mlx_new_window(data.mlx, TILE_SIZE * data.map_length, TILE_SIZE * data.map_height, "Hello world");
	if (!data.mlx_win)
	{
		mlx_destroy_display(data.mlx);
		return (free(data.mlx), 1);
	}
	mlx_hook(data.mlx_win, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.mlx_win, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	// if (argc == 2)
	// {
		// ft_map_check(&data, "maps.ber");
		// ft_map_invalid(data.map);
	// }
	set_img(&data);
	printf("%d %d\n", data.img.width, data.img.height);
	// print_img(&data, &data.img, 1, 1);
	ft_printf_map(&data);
	// int i = 0;
	// int j = 0;
	// while (i < 15)
	// {
	// 	while (j < 15)
	// 	{
	// 		print_img_grass(&data, &data.img, i, j);
	// 		j++;
	// 	}
	// 	j = 0;
	// 	i++;
	// }

	mlx_loop(data.mlx);
}
