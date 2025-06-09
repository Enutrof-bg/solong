/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:30:37 by kevwang           #+#    #+#             */
/*   Updated: 2025/05/26 15:30:38 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		ft_map_check(&data, argv[1]);
		data.mlx = mlx_init();
		if (!data.mlx)
			return (1);
		data.mlx_win = mlx_new_window(data.mlx,
				TILE_SIZE * data.map_length,
				TILE_SIZE * data.map_height, "so_long");
		if (!data.mlx_win)
		{
			mlx_destroy_display(data.mlx);
			return (free(data.mlx), 1);
		}
		set_img(&data);
		mlx_key_hook(data.mlx_win, &on_keypress, &data);
		mlx_hook(data.mlx_win, DestroyNotify,
			StructureNotifyMask, &on_destroy, &data);
		ft_printf_map(&data);
		mlx_loop(data.mlx);
	}
	else
		return (ft_printf("Error\n2 arg expected\n"), 0);
}
