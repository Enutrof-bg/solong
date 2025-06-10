/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:34:13 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/10 11:34:14 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_anim_key_print(t_data *data, int frame, int i, int j)
{
	if (frame == 0)
	{
		mlx_put_image_to_window(data->mlx,
			data->mlx_win, data->anim.img_key_anim1,
			data->img.width * j, data->img.height * i);
	}
	if (frame == 1)
	{
		mlx_put_image_to_window(data->mlx,
			data->mlx_win, data->anim.img_key_anim2,
			data->img.width * j, data->img.height * i);
	}
	if (frame == 2)
	{
		mlx_put_image_to_window(data->mlx,
			data->mlx_win, data->anim.img_key_anim3,
			data->img.width * j, data->img.height * i);
	}
	if (frame == 3)
	{
		mlx_put_image_to_window(data->mlx,
			data->mlx_win, data->anim.img_key_anim4,
			data->img.width * j, data->img.height * i);
	}
}

void	ft_anim_key(t_data *data, int frame)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
			{
				ft_anim_key_print(data, frame, i, j);
			}
			j++;
		}
		i++;
	}
}

void	ft_anim_char_print(t_data *data, int frame)
{
	if (frame == 0)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->anim.img_anim1,
			data->img.width * data->player_y,
			data->img.height * data->player_x);
	}
	if (frame == 1)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->anim.img_anim2,
			data->img.width * data->player_y,
			data->img.height * data->player_x);
	}
	if (frame == 2)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->anim.img_anim3,
			data->img.width * data->player_y,
			data->img.height * data->player_x);
	}
	if (frame == 3)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->anim.img_anim4,
			data->img.width * data->player_y,
			data->img.height * data->player_x);
	}
}

int	ft_anim(t_data *data)
{
	static int	frame = 0;

	ft_anim_char_print(data, frame);
	ft_anim_key(data, frame);
	frame++;
	if (frame >= 4)
		frame = 0;
	usleep(100000);
	return (0);
}
