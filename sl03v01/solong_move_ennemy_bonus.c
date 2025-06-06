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

void ft_check_dead(t_data *data)
{
	if (data->player_x == data->ennemy_x && data->player_y == data->ennemy_y)
		on_destroy(data);
}

void ft_set_ennemy(t_data *data)
{
	data->ennemy_x = 10;
	data->ennemy_y = 10;
	print_img_ennemy(data, &data->img, data->ennemy_y, data->ennemy_x);
}

void ft_ennemy_move(t_data *data)
{
	int static set = 0;
	int static move = 0;
	
	if (set == 0)
	{
		ft_set_ennemy(data);
		set = 1;
	}
	if (move < 5)
	{
		if (data->ennemy_y != data->player_y)
			print_img_grass(data, &data->img, data->ennemy_y, data->ennemy_x);
		print_img_ennemy(data, &data->img, data->ennemy_y + 1, data->ennemy_x);
		data->ennemy_y++;
		move++;
	}
	else if (move < 10)
	{
		if (data->ennemy_y != data->player_y)
			print_img_grass(data, &data->img, data->ennemy_y, data->ennemy_x);
		print_img_ennemy(data, &data->img, data->ennemy_y - 1, data->ennemy_x);
		data->ennemy_y--;
		move++;
	}
	else if (move >= 10)
		move = 0;
}

// int	ft_move_right(t_data *data)
// {
// 	if (data->map[data->player_x][data->player_y + 1] != '1')
// 	{		
// 		if (data->map[data->player_x][data->player_y + 1] == 'E'
// 			&& data->player_collect < data->count_c)
// 			return (0);
// 		if (data->map[data->player_x][data->player_y + 1] == 'C')
// 			data->player_collect++;
// 		if (data->player_collect == data->count_c)
// 			print_img_exit_open(data, &data->img, data->exit_y, data->exit_x);
// 		if (data->map[data->player_x][data->player_y + 1] == 'E'
// 			&& data->player_collect == data->count_c)
// 		{
// 			data->player_end = 1;
// 			return (1);
// 		}
// 		print_img_grass(data, &data->img, data->player_y, data->player_x);
// 		print_img_char(data, &data->img, data->player_y + 1, data->player_x);
// 		data->player_y++;
// 		return (1);
// 	}
// 	return (0);
// }