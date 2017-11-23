/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:02:14 by llopez            #+#    #+#             */
/*   Updated: 2017/11/23 10:17:30 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	display_map(char **map)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			ft_putchar((char)map[y][x]);
			x++;
		}
		y++;
		ft_putchar('\n');
	}
}

char		**clear_map(char **map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			map[y][x] = '.';
			x++;
		}
		y++;
	}
	return (map);
}

char		**clear_piece(int *piece, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == (piece[8] + 64))
				map[y][x] = '.';
			x++;
		}
		y++;
	}
	return (map);
}
