/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_print_img2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:07:41 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/06 12:07:42 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	print_img_exit_open(t_data *data, t_image *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, img->img_exit_open,
		img->width * x, img->height * y);
}

