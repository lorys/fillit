/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <llopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 23:36:35 by llopez            #+#    #+#             */
/*   Updated: 2017/11/23 10:40:16 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

static int	inttab(char **tab)
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

	map_len = inttab(map);
	newmap = (char **)malloc(sizeof(char *) * (map_len + 1));
	newmap[map_len] = NULL;
	i = 0;
	while (i < (map_len / 2))
	{
		x = 0;
		newmap[i] = (char *)malloc(sizeof(char) * (map_len + 1));
		while (x < (map_len / 2))
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

	y = 0;
	min_x = -1;
	min_y = -1;
	coords = (int *)malloc(sizeof(int) * 8);
	coords_i = 0;
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
				coords[coords_i] = x;
				coords[coords_i + 1] = y;
				coords_i += 2;
			}
			x++;
		}
		y++;
	}
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
		if (map[y + piece[i + 1]][x + piece[i]] != '.' \
				|| map[y + piece[i + 1]][x + piece[i]] == '\0' \
				|| map[y + piece[i + 1]] == NULL)
			return (NULL);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		map[y + piece[i + 1]][x + piece[i]] = '#';
		i = i + 2;
	}
	return (map);
}
