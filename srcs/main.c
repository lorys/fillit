/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <llopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 01:52:42 by llopez            #+#    #+#             */
/*   Updated: 2017/12/06 11:39:10 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

static int		find_pieces(char nbr_pieces, char **map)
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
			if (map[y][x] == (64 + nbr_pieces))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static int		find_all_pieces(char **pieces_map, char **map)
{
	int		count;

	count = 1;
	while (find_pieces(count, map) == 1 && count <= (inttab(pieces_map) / 4))
		count++;
	if (count == (inttab(pieces_map) / 4) + 1)
		return (1);
	return (0);
}

int				sherlock(char **pieces_map, char **map, int count_pieces)
{
	int		y;
	int		x;
	int		*pieces;

	y = 0;
	if (find_all_pieces(pieces_map, map) == 1)
		return (1);
	if (!(pieces = read_piece(count_pieces, pieces_map)))
		return (-1);
	while (y <= inttab(map))
	{
		x = 0;
		while (x <= (int)ft_strlen(map[0]))
		{
			clear_piece(pieces, map);
			if (put_piece(x, y, pieces, map) != NULL && \
				sherlock(pieces_map, map, count_pieces + 1))
				if (find_all_pieces(pieces_map, map))
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static int		ft_error(int argc)
{
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	return (1);
}

int				main(int argc, char **argv)
{
	if (ft_error(argc) == 0)
		return (0);
	if (!read_file(argv[1]) || check_pieces(read_file(argv[1])) == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	if (meanwhile(argv) == -1)
		return (0);
	return (0);
}
