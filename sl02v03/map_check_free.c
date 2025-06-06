/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:34:08 by kevwang           #+#    #+#             */
/*   Updated: 2025/06/06 11:34:09 by kevwang          ###   ########.fr       */
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

void	ft_free_double_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
