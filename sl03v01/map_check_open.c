/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:37:11 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/06 11:37:12 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_check_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[0] != '1' || str[i - 1] != '1')
		return (1);
	return (0);
}

char	*ft_open(t_data *data, char *filename)
{
	char	*str;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFilename invalid\n");
		exit(EXIT_FAILURE);
	}	
	data->map_height = 0;
	str = get_next_line(fd);
	if (!str)
		return (NULL);
	close(fd);
	return (str);
}

int	ft_check_filename(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	i = i - 4;
	if (filename[i] == '.' && filename[i + 1] == 'b'
		&&filename[i + 2] == 'e' && filename[i + 3] == 'r')
		return (0);
	else
		return (1);
}

char	**ft_open_map(t_data *data, char *filename)
{
	char	*str;
	char	**result;

	if (ft_check_filename(filename) == 1)
	{
		ft_printf("Error\nFilename invalid\n");
		exit(EXIT_FAILURE);
	}
	str = ft_open(data, filename);
	if (!str)
		return (NULL);
	if (ft_check_newline(str) == 1)
	{
		free(str);
		ft_printf("Error\nMap invalid\n");
		exit(EXIT_FAILURE);
	}
	result = ft_split(str, '\n');
	if (!result)
		return (free(str), NULL);
	free(str);
	ft_map_size(data, result);
	return (result);
}
