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

char	*ft_open(t_data *data, char *filename)
{
	char	*str;
	char	*result;
	char	*temp;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFilename invalid\n");
		exit(EXIT_FAILURE);
	}	
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

int ft_check_filename(char *filename)
{
	int i;

	i = 0;
	while (filename[i])
		i++;
	i = i - 4;
	if (filename[i] == '.' && filename[i + 1] == 'b'
		&&filename[i + 2] == 'e' &&filename[i + 3] == 'r')
		return (0);
	else
		return (1);
}

char **ft_open_map(t_data *data, char *filename)
{
	char *str;
	char **result;

	if (ft_check_filename(filename) == 1)
	{
		ft_printf("Error\nFilename invalid\n");
		exit(EXIT_FAILURE);
	}
	str = ft_open(data, filename);
	result = ft_split(str, '\n');
	ft_map_size(data, result);
	free(str);
	return (result);
}
