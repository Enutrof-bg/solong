/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:03:23 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/06 12:04:01 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void set_img(t_data *data)
{
	data->img.width = 64;
	data->img.height = 64;
	data->player_end = 0;
	data->player_collect = 0;
	data->img.img_grass = NULL;
	data->img.img_wall = NULL;
	data->img.img_char = NULL;
	data->img.img_key = NULL;
	data->img.img_exit = NULL;
	data->img.img_exit_open = NULL;
	data->img.dest_grass = "./sproutxpm/Sol.xpm";
	data->img.img_grass = mlx_xpm_file_to_image(data->mlx, data->img.dest_grass, &data->img.width, &data->img.height);
	if (!data->img.img_grass)
	{
	    ft_printf("Error\nXPM file invalid\n");
	    on_destroy(data);
	    exit(EXIT_FAILURE);
	}

	data->img.dest_wall = "./sproutxpm/wall.xpm";
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx, data->img.dest_wall, &data->img.width, &data->img.height);
	if (!data->img.img_wall)
	{
	    ft_printf("Error\nXPM file invalid\n");
	    on_destroy(data);
	    exit(EXIT_FAILURE);
	}

	data->img.dest_char = "./sproutxpm/char.xpm";
	data->img.img_char = mlx_xpm_file_to_image(data->mlx, data->img.dest_char, &data->img.width, &data->img.height);
	if (!data->img.img_char)
	{
		ft_printf("Error\nXPM file invalid\n");
	    on_destroy(data);
	    exit(EXIT_FAILURE);
	}

	data->img.dest_key = "./sproutxpm/key.xpm";
	data->img.img_key = mlx_xpm_file_to_image(data->mlx, data->img.dest_key, &data->img.width, &data->img.height);
	if (!data->img.img_key)
	{
	    ft_printf("Error\nXPM file invalid\n");
	    on_destroy(data);
	    exit(EXIT_FAILURE);
	}

	data->img.dest_exit = "./sproutxpm/exit.xpm";
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx, data->img.dest_exit, &data->img.width, &data->img.height);
	if (!data->img.img_exit)
	{
	    ft_printf("Error\nXPM file invalid\n");
	    on_destroy(data);
	    exit(EXIT_FAILURE);
	}

	data->img.dest_exit_open = "./sproutxpm/open.xpm";
	data->img.img_exit_open = mlx_xpm_file_to_image(data->mlx, data->img.dest_exit_open, &data->img.width, &data->img.height);
	if (!data->img.img_exit_open)
	{
	    ft_printf("Error\nXPM file invalid\n");
	    on_destroy(data);
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
			if (data->map[i][j] == 'C')
				print_img_key(data, &data->img, j, i);
			if (data->map[i][j] == 'E')
				print_img_exit(data, &data->img, j, i);
			j++;
		}
		j = 0;
		i++;
	}
}