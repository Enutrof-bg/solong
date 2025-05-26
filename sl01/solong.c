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

void	print_img(t_data *data, t_image *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, img->img,
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
	data->img.width = 16;
	data->img.height = 16;
	data->img.imgdest = "./sproutxpm/Grass.xpm";
	data->img.img = mlx_xpm_file_to_image(data->mlx, data->img.imgdest, &data->img.width, &data->img.height);
	if (!data->img.img)
	{
    printf("Erreur: Impossible de charger l'image XPM\n");
    exit(EXIT_FAILURE);
	}
}

int main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.mlx_win = mlx_new_window(data.mlx, TILE_SIZE * 15, TILE_SIZE * 15, "Hello world");
	if (!data.mlx_win)
	{
		mlx_destroy_display(data.mlx);
		return (free(data.mlx), 1);
	}

	mlx_hook(data.mlx_win, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.mlx_win, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

	set_img(&data);
	printf("%d %d\n", data.img.width, data.img.height);
	// print_img(&data, &data.img, 1, 1);

	int i = 0;
	int j = 0;
	while (i < 15)
	{
		while (j < 15)
		{
			print_img(&data, &data.img, i, j);
			j++;
		}
		j = 0;
		i++;
	}

	mlx_loop(data.mlx);
}
