/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:53:39 by kevwang           #+#    #+#             */
/*   Updated: 2025/05/27 11:53:40 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	**ft_copy_double_char(char **tab)
{
	int		i;
	int		j;
	char	**newtab;

	i = 0;
	j = 0;
	while (tab[i])
		i++;
	newtab = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (tab[i])
	{
		newtab[i] = ft_strdup(tab[i]);
		i++;
	}
	newtab[i] = 0;
	return (newtab);
}

void	ft_map_path_set(char **map, int i, int j)
{
	if (map[i][j] == 'P')
		map[i][j] = ' ';
	if (map[i][j] == ' ' && map[i][j + 1] != '1')
		map[i][j + 1] = ' ';
	if (map[i][j] == ' ' && map[i][j - 1] != '1')
		map[i][j - 1] = ' ';
	if (map[i][j] == ' ' && map[i + 1][j] != '1')
		map[i + 1][j] = ' ';
	if (map[i][j] == ' ' && map[i - 1][j] != '1')
		map[i - 1][j] = ' ';
}

void	ft_map_path(t_data *data, char **map)
{
	int	i;
	int	j;
	int	n;

	n = 0;
	while (n < data->map_length * data->map_height)
	{
		i = 0;
		while (map[i])
		{
			j = 0;
			while (map[i][j])
			{
				ft_map_path_set(map, i, j);
				j++;
			}
			i++;
		}
		n++;
	}
}

int	ft_map_key_path(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	ft_check_path(t_data *data)
{
	char	**temp;

	temp = ft_copy_double_char(data->map);
	ft_map_path(data, temp);
	if (temp[data->exit_x][data->exit_y] == ' ' && ft_map_key_path(temp) == 0)
	{
		ft_free_double_tab(temp);
		return (0);
	}
	else
	{
		ft_printf("Error\nNo Path To Exit\n");
		ft_free_double_tab(temp);
		return (1);
	}
}
