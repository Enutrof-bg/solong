/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:03:54 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/06 12:03:55 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	on_destroy(t_data *data)
{
	if (data->img.img_grass)
		mlx_destroy_image(data->mlx, data->img.img_grass);
	if (data->img.img_wall)
		mlx_destroy_image(data->mlx, data->img.img_wall);
	if (data->img.img_char)
		mlx_destroy_image(data->mlx, data->img.img_char);
	if (data->img.img_key)
		mlx_destroy_image(data->mlx, data->img.img_key);
	if (data->img.img_exit)
		mlx_destroy_image(data->mlx, data->img.img_exit);
	if (data->img.img_exit_open)
		mlx_destroy_image(data->mlx, data->img.img_exit_open);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	if (data->map)
		ft_free_double_tab(data->map);
	free(data->mlx);
	exit(0);
	return (0);
}
