/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_move_ennemy_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:23:20 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/06 15:23:21 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_set_ennemy(t_data *data)
{
	data->ennemy_x = 10;
	data->ennemy_y = 10;
	print_img_ennemy(data, &data->img, data->ennemy_y, data->ennemy_x);
}

void	ft_ennemy_move_2(t_data *data, int move)
{
	if (move < 5)
	{
		if ((data->ennemy_y != data->player_y)
			|| (data->ennemy_x != data->player_x))
			print_img_grass(data, &data->img, data->ennemy_y, data->ennemy_x);
		print_img_ennemy(data, &data->img, data->ennemy_y + 1, data->ennemy_x);
		data->ennemy_y++;
	}
	else if (move < 10)
	{
		if ((data->ennemy_y != data->player_y)
			|| (data->ennemy_x != data->player_x))
			print_img_grass(data, &data->img, data->ennemy_y, data->ennemy_x);
		print_img_ennemy(data, &data->img, data->ennemy_y - 1, data->ennemy_x);
		data->ennemy_y--;
	}
}

void	ft_ennemy_move(t_data *data)
{
	int static	set = 0;
	int static	move = 0;

	if (set == 0)
	{
		ft_set_ennemy(data);
		set = 1;
	}
	if (move >= 10)
		move = 0;
	ft_ennemy_move_2(data, move);
	move++;
}
