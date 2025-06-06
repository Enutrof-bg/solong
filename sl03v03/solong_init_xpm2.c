/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_init_xpm2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:42:35 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/06 12:42:36 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_get_img_exit_open(t_data *data)
{	
	data->img.dest_exit_open = "./sproutxpm/open.xpm";
	data->img.img_exit_open = mlx_xpm_file_to_image(data->mlx,
			data->img.dest_exit_open, &data->img.width, &data->img.height);
	if (!data->img.img_exit_open)
	{
		ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
}
