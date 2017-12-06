/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <llopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 23:36:35 by llopez            #+#    #+#             */
/*   Updated: 2017/12/02 17:01:26 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				inttab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

char			**map_generator(int len)
{
	char	**newmap;
	int		i;
	int		map_len;
	int		x;

	map_len = len;
	if (!(newmap = (char **)malloc(sizeof(char *) * (map_len + 1))))
		return (NULL);
	newmap[map_len] = NULL;
	i = 0;
	while (i < map_len)
	{
		x = 0;
		if (!(newmap[i] = (char *)malloc(sizeof(char) * (map_len + 1))))
			return (NULL);
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

static void		piece_placer(t_resolve *lst, int i, char **map)
{
	while (lst->y < 4)
	{
		lst->x = 0;
		while (lst->x < 4)
		{
			if (map[((i * 4) - 4) + lst->y][lst->x] == '#')
			{
				lst->min_x = (lst->min_x == -1) ? lst->x : lst->min_x;
				lst->min_x = (lst->min_x > lst->x) ? lst->x : lst->min_x;
				lst->min_y = (lst->min_y == -1) ? lst->y : lst->min_y;
				lst->min_y = (lst->min_y > lst->y) ? lst->y : lst->min_y;
				lst->coords[lst->coords_i] = lst->x;
				lst->coords[lst->coords_i + 1] = lst->y;
				lst->coords_i += 2;
			}
			lst->x++;
		}
		lst->y++;
	}
}

int				*read_piece(int i, char **map)
{
	t_resolve	lst;

	lst.y = 0;
	lst.min_x = -1;
	lst.min_y = -1;
	lst.x_max = 0;
	lst.y_max = 0;
	if (!(lst.coords = (int *)malloc(sizeof(int) * 11)))
		return (NULL);
	lst.coords_i = 0;
	lst.coords[8] = i;
	piece_placer(&lst, i, map);
	lst.y = -2;
	while ((lst.y += 2) < 8)
	{
		lst.coords[lst.y] = lst.coords[lst.y] - lst.min_x;
		lst.coords[lst.y + 1] = lst.coords[lst.y + 1] - lst.min_y;
		lst.x_max = (lst.coords[lst.y] > lst.x_max) ? \
		lst.coords[lst.y] : lst.x_max;
		lst.y_max = (lst.coords[lst.y + 1] > lst.y_max) ? \
		lst.coords[lst.y + 1] : lst.y_max;
	}
	lst.coords[9] = lst.x_max + 1;
	lst.coords[10] = lst.y_max + 1;
	return (lst.coords);
}

char			**put_piece(int x, int y, int *piece, char **map)
{
	int	i;

	i = 0;
	if (inttab(map) < (y + piece[10]))
		return (NULL);
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
