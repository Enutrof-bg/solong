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

void	ft_map_invalid(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	free(map[i]);
	while (i > 0)
	{
		i--;
		free(map[i]);
	}
	free(map);
	exit(1);
}

char	*ft_open(t_data *data, char *filename)
{
	char	*str;
	char	*result;
	char	*temp;
	int		fd;

	fd = open(filename, O_RDONLY);
	data->map_height = 0;
	//ERREUR FD //TODO
	result = ft_strdup("");
	//erreur malloc todo
	str = get_next_line(fd);
	while (str != NULL)
	{
		temp = ft_strjoin(result, str);
		free(result);
		result = NULL;
		result = temp;
		free(str);
		str = NULL;
		str = get_next_line(fd);
	}
	close(fd);
	return (result);
}

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
					ft_printf("Map dimmensions invalides");// a refaire TODO TODO
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

char **ft_open_map(t_data *data, char *filename)
{
	char *str;
	char **result;

	str = ft_open(data, filename);
	result = ft_split(str, '\n');
	ft_map_size(data, result);
	free(str);
	return (result);
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
			return (ft_printf("Map mur invalide"), (1)); //erreur todo a refaire
	}
	while (i < data->map_height)
	{
		if (data->map[i][0] == '1' && data->map[i][data->map_length - 1] == '1')
			i++;
		else
			return (ft_printf("Map mur invalide"), 1); //erreur todo a refaire
	}
	return (0);
}

int	ft_map_check_components_double(t_data *data)
{
	if (data->count_e != 1 || data->count_p != 1 || data->count_c < 1)
		return (ft_printf("Map components invalides"), 1); //TODO ERREUR
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
				return (ft_printf("Components non autorises"), 1); //TODO ERREUR
			j++;
		}
		j = 0;
		i++;
	}
	return (ft_map_check_components_double(data));
}

void	ft_set_map(t_data *data)
{
	data->map_height = 0;
	data->map_length = 0;
	data->count_e = 0;
	data->count_p = 0;
	data->count_c = 0;
}

void	ft_map_path_set(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'P')
		data->map[i][j] = ' ';
	if (data->map[i][j] == ' ' && data->map[i][j + 1] != '1')
		data->map[i][j + 1] = ' ';
	if (data->map[i][j] == ' ' && data->map[i][j - 1] != '1')
		data->map[i][j - 1] = ' ';
	if (data->map[i][j] == ' ' && data->map[i + 1][j] != '1')
		data->map[i + 1][j] = ' ';
	if (data->map[i][j] == ' ' && data->map[i - 1][j] != '1')
		data->map[i - 1][j] = ' ';
}

void	ft_map_path(t_data *data)
{
	int i;
	int j;
	int n;

	n = 0;
	while (n < data->map_length * data->map_height)
	{
		i = 0;
		while (data->map[i])
		{
			j = 0;
			while (data->map[i][j])
			{
				ft_map_path_set(data, i, j);
				j++;
			}
			i++;
		}
		n++;
	}
	if (data->map[data->exit_x][data->exit_y] == ' ')
		ft_printf("Path Valid\n");
	else
		ft_printf("No Path To Exit\n");
}

void ft_map_check(t_data *data, char *filename)
{
	ft_set_map(data);
	data->map = ft_open_map(data, filename);
	if (ft_map_test_wall(data) == 1)
		ft_map_invalid(data->map);
	if (ft_map_check_components(data) == 1)
		ft_map_invalid(data->map);
	// ft_printf("map_height:%d\nmap_length:%d\n", data->map_height, data->map_length);
	// ft_printf("e:%d c:%d p:%d\n", data->count_e, data->count_c, data->count_p);

	// ft_map_path(data); //faire une fonction qui creer une copie de char **map

	// int i = 0;
	// while (data->map[i])
	// {
	// 	ft_printf("%s\n", data->map[i]);
	// 	i++;
	// }
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