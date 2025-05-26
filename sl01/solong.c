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
void my_mlx_pixel_put(t_image *test, int x, int y, int color)
{
	char *dst;

	dst = test->addr + (y * test->line_length + x * (test->bits_per_pixels / 8));
	*(unsigned int*)dst = color;
}

int on_destroy(t_data *data)
{
	// mlx_destroy_image(data->mlx, );
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

int main(void)
{
	// void *mlx;
	// void *mlx_win;
	t_data	data;
	t_image img;

	img.x = 16;
	img.y = 16;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.mlx_win = mlx_new_window(data.mlx, TILE_SIZE * 32, TILE_SIZE * 32, "Hello world");
	if (!data.mlx_win)
		return (free(data.mlx_win), 1);

	mlx_hook(data.mlx_win, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.mlx_win, DestroyNotify, StructureNotifyMask, &on_destroy, &data);


	// img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixels, &img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 50, 50, rand() % 0x1000000);

	img.img = mlx_xpm_file_to_image(data.mlx, "/sproutxpm/char/Basic Charakter Spritesheet.xpm", &img.x, &img.y);
	printf("%d %d\n", img.x, img.y);
	mlx_put_image_to_window(data.mlx, data.mlx_win, img.img, 0, 0);

	mlx_loop(data.mlx);
}
