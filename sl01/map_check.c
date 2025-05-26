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

int main(void)
{
	int fd;
	char *line = NULL;
	int i;
	int len;
	char **tab;
	int index;

	index = 0;
	i = 0;
	len = 0;
	fd = open("maps.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		len = ft_strlen(line);

		printf("%d %s",len, line);

		free(line);
		line = get_next_line(fd);
		i++;
		// len = ft_strlen(line);
	}
	free(line);
	printf("\n%d\n", i);
	close(fd);
	fd = open("maps.txt", O_RDONLY);
	tab = malloc(sizeof(char *) * (i + 1));
	// if (!tab)
	// 	return (NULL);

	line = get_next_line(fd);
	while (line != NULL)
	{
		tab[index] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
}