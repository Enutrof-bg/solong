/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_print_ennemy_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:23:28 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/06 15:23:31 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	print_img_ennemy(t_data *data, t_image *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, img->img_ennemy,
		img->width * x, img->height * y);
}

void	print_img_ennemy_mort(t_data *data, t_image *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, img->img_ennemy_mort,
		img->width * x, img->height * y);
}

void	ft_move_all_ennemy(t_data *data)
{
	ft_check_dead(data);
	ft_ennemy_move(data);
	ft_ennemy_move_mort(data);
	ft_check_dead(data);
}

void	ft_check_dead(t_data *data)
{
	if (data->player_x == data->ennemy_x && data->player_y == data->ennemy_y)
		on_destroy(data);
	if (data->player_x == data->ennemy_mort_x
		&& data->player_y == data->ennemy_mort_y)
		on_destroy(data);
}
