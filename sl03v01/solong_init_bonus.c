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

void	set_img_bonus(t_data *data)
{
	data->img.img_ennemy = NULL;
	data->img.img_ennemy_mort = NULL;
	ft_get_img_ennemy(data);
	ft_get_img_ennemy_mort(data);
	data->anim.img_anim1 = NULL;
	data->anim.img_anim2 = NULL;
	data->anim.img_anim3 = NULL;
	data->anim.img_anim4 = NULL;
	ft_get_img_anim1(data);
	ft_get_img_anim2(data);
	ft_get_img_anim3(data);
	ft_get_img_anim4(data);
	data->anim.img_key_anim1 = NULL;
	data->anim.img_key_anim2 = NULL;
	data->anim.img_key_anim3 = NULL;
	data->anim.img_key_anim4 = NULL;
	ft_get_img_key_anim1(data);
	ft_get_img_key_anim2(data);
	ft_get_img_key_anim3(data);
	ft_get_img_key_anim4(data);
}

void	set_img(t_data *data)
{
	data->img.width = 64;
	data->img.height = 64;
	data->player_end = 0;
	data->player_collect = 0;
	data->ennemy_x = 10;
	data->ennemy_y = 10;
	data->img.img_grass = NULL;
	data->img.img_wall = NULL;
	data->img.img_char = NULL;
	data->img.img_key = NULL;
	data->img.img_exit = NULL;
	data->img.img_exit_open = NULL;
	ft_get_img_grass(data);
	ft_get_img_wall(data);
	ft_get_img_char(data);
	ft_get_img_key(data);
	ft_get_img_exit(data);
	ft_get_img_exit_open(data);
	set_img_bonus(data);
}

void	ft_printf_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
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
		i++;
	}
	ft_set_ennemy(data);
	ft_set_ennemy_mort(data);
}
