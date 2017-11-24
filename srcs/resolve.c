/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <llopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 23:36:35 by llopez            #+#    #+#             */
/*   Updated: 2017/11/24 17:05:35 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

int	inttab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

char		**map_generator(char **map)
{
	char	**newmap;
	int		i;
	int		map_len;
	int		x;

	map_len = ft_sqrt(inttab(map));
	newmap = (char **)malloc(sizeof(char *) * (map_len + 1));
	newmap[map_len] = NULL;
	i = 0;
	while (i < map_len)
	{
		x = 0;
		newmap[i] = (char *)malloc(sizeof(char) * (map_len + 1));
		while (x < map_len)
		{
			newmap[i][x] = '.';
			x++;
		}
		newmap[i][map_len] = '\0';
		i++;
	}
	return (newmap);
}

int		*read_piece(int i, char **map)
{
	int		min_x;
	int		min_y;
	int		y;
	int		x;
	int		*coords;
	int		coords_i;
	int		x_max;
	int		y_max;

	y = 0;
	min_x = -1;
	min_y = -1;
	x_max = 0;
	y_max = 0;
	coords = (int *)malloc(sizeof(int) * 11);
	coords_i = 0;
	coords[8] = i;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (map[((i * 4) - 4) + y][x] == '#')
			{
				min_x = (min_x == -1) ? x : min_x;
				min_x = (min_x > x) ? x : min_x;
				min_y = (min_y == -1) ? y : min_y;
				min_y = (min_y > y) ? y : min_y;

				x_max = (x > x_max) ? x : x_max;
				y_max = (y > y_max) ? y : y_max;
				coords[coords_i] = x;
				coords[coords_i + 1] = y;
				coords_i += 2;
			}
			x++;
		}
		y++;
	}
	coords[9] = x_max;
	coords[10] = y_max;
	y = 0;
	while (y < 8)
	{
		coords[y] = coords[y] - min_x;
		coords[y + 1] = coords[y + 1] - min_y;
		y += 2;
	}
	return (coords);
}

char		**put_piece(int x, int y, int *piece, char **map)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (map[y + piece[i + 1]][x + piece[i]] != '.')
			return (NULL);
		i = i + 2;
	}
	i = 0;
	while (i < 8)
	{
		map[y + piece[i + 1]][x + piece[i]] = piece[8] + 64;
		i = i + 2;
	}
	return (map);
}
