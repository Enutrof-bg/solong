/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_compo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:38:08 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/06 11:38:10 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_map_size(t_data *data, char **map)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j + 1] == '\0')
			{
				if ((j + 1) != len)
				{
					ft_printf("Error\nMap dimmensions invalides\n");// a refaire TODO TODO
					ft_map_invalid(map);
				}
			}
			j++;
		}
		i++;
	}
	data->map_height = i;
	data->map_length = len;
}

int	ft_map_test_wall(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < data->map_length)
	{
		if (data->map[0][j] == '1' && data->map[data->map_height - 1][j] == '1')
			j++;
		else
			return (ft_printf("Error\nMap mur invalide\n"), (1)); //erreur todo a refaire
	}
	while (i < data->map_height)
	{
		if (data->map[i][0] == '1' && data->map[i][data->map_length - 1] == '1')
			i++;
		else
			return (ft_printf("Error\nMap mur invalide\n"), 1); //erreur todo a refaire
	}
	return (0);
}

int	ft_map_check_components_double(t_data *data)
{
	if (data->count_e != 1 || data->count_p != 1 || data->count_c < 1)
		return (ft_printf("Error\nMap components invalides\n"), 1); //TODO ERREUR
	else
		return (0);
}

int	ft_map_check_components(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
			{
				data->count_e++;
				data->exit_x = i;
				data->exit_y = j;
			}
			else if (data->map[i][j] == 'P')
			{
				data->count_p++;
				data->player_x = i;
				data->player_y = j;
			}
			else if (data->map[i][j] == 'C')
				data->count_c++;
			else if (data->map[i][j] != '0' && data->map[i][j] != '1')
				return (ft_printf("Error\nComponents non autorises\n"), 1); //TODO ERREUR
			j++;
		}
		j = 0;
		i++;
	}
	return (ft_map_check_components_double(data));
}