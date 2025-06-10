/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_init_xpm_char_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:43:19 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/10 11:43:20 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_get_img_anim1(t_data *data)
{
	data->anim.dest_anim1 = "./textures/char_im1.xpm";
	data->anim.img_anim1 = mlx_xpm_file_to_image(data->mlx,
			data->anim.dest_anim1, &data->img.width, &data->img.height);
	if (!data->anim.img_anim1)
	{
		ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
}

void	ft_get_img_anim2(t_data *data)
{
	data->anim.dest_anim2 = "./textures/char_im2.xpm";
	data->anim.img_anim2 = mlx_xpm_file_to_image(data->mlx,
			data->anim.dest_anim2, &data->img.width, &data->img.height);
	if (!data->anim.img_anim2)
	{
		ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
}

void	ft_get_img_anim3(t_data *data)
{
	data->anim.dest_anim3 = "./textures/char_im3.xpm";
	data->anim.img_anim3 = mlx_xpm_file_to_image(data->mlx,
			data->anim.dest_anim3, &data->img.width, &data->img.height);
	if (!data->anim.img_anim3)
	{
		ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
}

void	ft_get_img_anim4(t_data *data)
{
	data->anim.dest_anim4 = "./textures/char_im4.xpm";
	data->anim.img_anim4 = mlx_xpm_file_to_image(data->mlx,
			data->anim.dest_anim4, &data->img.width, &data->img.height);
	if (!data->anim.img_anim4)
	{
		ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
}
