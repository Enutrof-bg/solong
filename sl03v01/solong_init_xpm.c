/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_init_xpm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:42:30 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/06 12:42:31 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_get_img_grass(t_data *data)
{
	data->img.dest_grass = "./textures/Sol.xpm";
	data->img.img_grass = mlx_xpm_file_to_image(data->mlx,
			data->img.dest_grass, &data->img.width, &data->img.height);
	if (!data->img.img_grass)
	{
		ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
}

void	ft_get_img_wall(t_data *data)
{
	data->img.dest_wall = "./textures/wall.xpm";
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx,
			data->img.dest_wall, &data->img.width, &data->img.height);
	if (!data->img.img_wall)
	{
		ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
}

void	ft_get_img_char(t_data *data)
{
	data->img.dest_char = "./textures/char_im1.xpm";
	data->img.img_char = mlx_xpm_file_to_image(data->mlx,
			data->img.dest_char, &data->img.width, &data->img.height);
	if (!data->img.img_char)
	{
		ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
}

void	ft_get_img_key(t_data *data)
{
	data->img.dest_key = "./textures/key.xpm";
	data->img.img_key = mlx_xpm_file_to_image(data->mlx,
			data->img.dest_key, &data->img.width, &data->img.height);
	if (!data->img.img_key)
	{
		ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
}

void	ft_get_img_exit(t_data *data)
{
	data->img.dest_exit = "./textures/exit.xpm";
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx,
			data->img.dest_exit, &data->img.width, &data->img.height);
	if (!data->img.img_exit)
	{
		ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
}
