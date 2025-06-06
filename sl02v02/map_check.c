/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:26:46 by kevwang           #+#    #+#             */
/*   Updated: 2025/05/26 17:26:47 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_set_map(t_data *data)
{
	data->map_height = 0;
	data->map_length = 0;
	data->count_e = 0;
	data->count_p = 0;
	data->count_c = 0;
}

void ft_map_check(t_data *data, char *filename)
{
	ft_set_map(data);
	data->map = ft_open_map(data, filename);
	if (ft_map_test_wall(data) == 1)
		ft_map_invalid(data->map);
	if (ft_map_check_components(data) == 1)
		ft_map_invalid(data->map);
	if (ft_check_path(data) == 1)
		ft_map_invalid(data->map);
}

// int main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		t_data	data;

// 		ft_map_check(&data, argv[1]);
// 		// ft_map_invalid(data.map);
// 		// ft_set_map(&data);
// 		// data.map = ft_open_map(&data, argv[1]);
// 		// if (ft_map_test_wall(&data) == 1)
// 		// 	ft_map_invalid(data.map);
// 		// if (ft_map_check_components(&data) == 1)
// 		// 	ft_map_invalid(data.map);
// 		// ft_printf("map_height:%d\nmap_length:%d\n", data.map_height, data.map_length);
// 		// ft_printf("e:%d c:%d p:%d\n", data.count_e, data.count_c, data.count_p);
// 	}
// 	// map = ft_split(test, '\n');
// 	// ft_map_size(&data, map);
// 	// ft_map_invalid(map);
// 	// free(test);
// 	// int a = 0;
// 	// while (map[a])
// 	// {
// 	// 	ft_printf("%s\n", map[a]);
// 	// 	a++;
// 	// }
// 	// ft_printf("%d\n", a);
// }