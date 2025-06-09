/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_move_ennemy_mort_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:17:09 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/09 17:17:11 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_set_ennemy_mort(t_data *data)
{
	data->ennemy_mort_x = 3;
	data->ennemy_mort_y = 4;
	print_img_ennemy_mort(data,
		&data->img, data->ennemy_mort_y, data->ennemy_mort_x);
}

void ft_ennemy_move_mort_2(t_data *data, int move)
{
	if (move < 6)
	{
		if ((data->ennemy_mort_y != data->player_y)
			|| (data->ennemy_mort_x != data->player_x))
			print_img_grass(data,
				&data->img, data->ennemy_mort_y, data->ennemy_mort_x);
		print_img_ennemy_mort(data,
			&data->img, data->ennemy_mort_y, data->ennemy_mort_x + 1);
		data->ennemy_mort_x++;
	}
	else if (move < 12)
	{
		if ((data->ennemy_mort_y != data->player_y)
			|| (data->ennemy_mort_x != data->player_x))
			print_img_grass(data,
				&data->img, data->ennemy_mort_y, data->ennemy_mort_x);
		print_img_ennemy_mort(data,
			&data->img, data->ennemy_mort_y, data->ennemy_mort_x - 1);
		data->ennemy_mort_x--;
	}
}

void	ft_ennemy_move_mort(t_data *data)
{
	int static	set = 0;
	int static	move = 0;

	if (set == 0)
	{
		ft_set_ennemy_mort(data);
		set = 1;
	}
	if (move >= 12)
		move = 0;
	ft_ennemy_move_mort_2(data, move);
	move++;
}
