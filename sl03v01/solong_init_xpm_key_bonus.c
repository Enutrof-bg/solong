/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_init_xpm_key_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:42:08 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/10 11:42:09 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_get_img_key_anim1(t_data *data)
{
	data->anim.dest_key_anim1 = "./textures/key_anim1.xpm";
	data->anim.img_key_anim1 = mlx_xpm_file_to_image(data->mlx,
			data->anim.dest_key_anim1, &data->img.width, &data->img.height);
	if (!data->anim.img_key_anim1)
	{
		ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
}

void	ft_get_img_key_anim2(t_data *data)
{
	data->anim.dest_key_anim2 = "./textures/key_anim2.xpm";
	data->anim.img_key_anim2 = mlx_xpm_file_to_image(data->mlx,
			data->anim.dest_key_anim2, &data->img.width, &data->img.height);
	if (!data->anim.img_key_anim2)
	{
		ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
}

void	ft_get_img_key_anim3(t_data *data)
{
	data->anim.dest_key_anim3 = "./textures/key_anim3.xpm";
	data->anim.img_key_anim3 = mlx_xpm_file_to_image(data->mlx,
			data->anim.dest_key_anim3, &data->img.width, &data->img.height);
	if (!data->anim.img_key_anim3)
	{
		ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
}

void	ft_get_img_key_anim4(t_data *data)
{
	data->anim.dest_key_anim4 = "./textures/key_anim4.xpm";
	data->anim.img_key_anim4 = mlx_xpm_file_to_image(data->mlx,
			data->anim.dest_key_anim4, &data->img.width, &data->img.height);
	if (!data->anim.img_key_anim4)
	{
		ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
}
