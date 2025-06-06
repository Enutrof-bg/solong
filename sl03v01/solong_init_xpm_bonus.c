/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_init_xpm_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:22:09 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/06 15:22:10 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_get_img_ennemy(t_data *data)
{
	data->img.dest_ennemy = "./sproutxpm/ennemy.xpm";
	data->img.img_ennemy = mlx_xpm_file_to_image(data->mlx,
			data->img.dest_ennemy, &data->img.width, &data->img.height);
	if (!data->img.img_ennemy)
	{
		ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
}

void	ft_get_img_ennemy_mort(t_data *data)
{
	data->img.dest_ennemy_mort = "./sproutxpm/mort.xpm";
	data->img.img_ennemy_mort = mlx_xpm_file_to_image(data->mlx,
			data->img.dest_ennemy_mort, &data->img.width, &data->img.height);
	if (!data->img.img_ennemy_mort)
	{
		ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
}
