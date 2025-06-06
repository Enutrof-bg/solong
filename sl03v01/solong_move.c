/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:00:22 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/06 12:00:24 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_move_up(t_data *data)
{
	if (data->map[data->player_x - 1][data->player_y] != '1')
	{
		if (data->map[data->player_x - 1][data->player_y] == 'E'
			&& data->player_collect < data->count_c)
			return (0);
		if (data->map[data->player_x - 1][data->player_y] == 'C')
			data->player_collect++;
		if (data->player_collect == data->count_c)
			print_img_exit_open(data, &data->img, data->exit_y, data->exit_x);
		if (data->map[data->player_x - 1][data->player_y] == 'E'
			&& data->player_collect == data->count_c)
		{
			data->player_end = 1;
			return (1);
		}
		print_img_grass(data, &data->img, data->player_y, data->player_x);
		print_img_char(data, &data->img, data->player_y, data->player_x -1);
		data->player_x--;
		return (1);
	}
	return (0);
}

int	ft_move_down(t_data *data)
{
	if (data->map[data->player_x + 1][data->player_y] != '1')
	{
		if (data->map[data->player_x + 1][data->player_y] == 'E'
			&& data->player_collect < data->count_c)
			return (0);
		if (data->map[data->player_x + 1][data->player_y] == 'C')
			data->player_collect++;
		if (data->player_collect == data->count_c)
			print_img_exit_open(data, &data->img, data->exit_y, data->exit_x);
		if (data->map[data->player_x + 1][data->player_y] == 'E'
			&& data->player_collect == data->count_c)
		{
			data->player_end = 1;
			return (1);
		}
		print_img_grass(data, &data->img, data->player_y, data->player_x);
		print_img_char(data, &data->img, data->player_y, data->player_x + 1);
		data->player_x++;
		return (1);
	}
	return (0);
}

int	ft_move_left(t_data *data)
{
	if (data->map[data->player_x][data->player_y - 1] != '1')
	{		
		if (data->map[data->player_x][data->player_y - 1] == 'E'
			&& data->player_collect < data->count_c)
			return (0);
		if (data->map[data->player_x][data->player_y - 1] == 'C')
			data->player_collect++;
		if (data->player_collect == data->count_c)
			print_img_exit_open(data, &data->img, data->exit_y, data->exit_x);
		if (data->map[data->player_x][data->player_y - 1] == 'E'
			&& data->player_collect == data->count_c)
		{
			data->player_end = 1;
			return (1);
		}
		print_img_grass(data, &data->img, data->player_y, data->player_x);
		print_img_char(data, &data->img, data->player_y - 1, data->player_x);
		data->player_y--;
		return (1);
	}
	return (0);
}

int	ft_move_right(t_data *data)
{
	if (data->map[data->player_x][data->player_y + 1] != '1')
	{		
		if (data->map[data->player_x][data->player_y + 1] == 'E'
			&& data->player_collect < data->count_c)
			return (0);
		if (data->map[data->player_x][data->player_y + 1] == 'C')
			data->player_collect++;
		if (data->player_collect == data->count_c)
			print_img_exit_open(data, &data->img, data->exit_y, data->exit_x);
		if (data->map[data->player_x][data->player_y + 1] == 'E'
			&& data->player_collect == data->count_c)
		{
			data->player_end = 1;
			return (1);
		}
		print_img_grass(data, &data->img, data->player_y, data->player_x);
		print_img_char(data, &data->img, data->player_y + 1, data->player_x);
		data->player_y++;
		return (1);
	}
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	static int	count = 0;
	char		*temp;

	if (keysym == KEY_ESC)
		on_destroy(data);
	if (keysym == KEY_W || keysym == KEY_UP)
		count = count + ft_move_up(data);
	if (keysym == KEY_S || keysym == KEY_DOWN)
		count = count + ft_move_down(data);
	if (keysym == KEY_A || keysym == KEY_LEFT)
		count = count + ft_move_left(data);
	if (keysym == KEY_D || keysym == KEY_RIGHT)
		count = count + ft_move_right(data);
	ft_printf("PM:%d\n", count);
	temp = ft_itoa(count);
	print_img_wall(data, &data->img, 0, 0);
	mlx_string_put(data->mlx, data->mlx_win, 32, 32, 0x00FF0000, temp);
	free(temp);
	if (data->player_end == 1)
		on_destroy(data);
	return (0);
}
