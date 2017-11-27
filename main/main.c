/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <llopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 01:52:42 by llopez            #+#    #+#             */
/*   Updated: 2017/11/27 10:32:02 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <unistd.h>

int		find_pieces(char nbr_pieces, char **map)
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

int		find_all_pieces(char **pieces_map, char **map)
{
	int		count;

	count = 1;
	while (find_pieces(count, map) == 1 && count <= (inttab(pieces_map) / 4))
		count++;
	if (count == (inttab(pieces_map) / 4) + 1)
		return (1);
	return (0);
}

int		solver(char **pieces_map, char **map, int count_pieces)
{
	int		y;
	int		x;
	int		*pieces;

	y = 0;
	if (find_all_pieces(pieces_map, map) == 1)
		return (1);
	pieces = read_piece(count_pieces, pieces_map);
	while (y <= inttab(map))
	{
		x = 0;
		while (x <= ft_strlen(map[0]))
		{
			clear_piece(pieces, map);
			if (put_piece(x, y, pieces, map) != NULL && \
				solver(pieces_map, map, count_pieces + 1))
				if (find_all_pieces(pieces_map, map))
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char		**map;
	char		**pieces_map;
	int			map_len;

	if (check_pieces(read_file(argv[1])) == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	pieces_map = ft_strsplit(read_file(argv[1]), '\n');
	map_len = ft_sqrt(inttab(pieces_map));
	map = map_generator(map_len);
	while (solver(pieces_map, map, 1) == 0)
	{
		map_len++;
		map = map_generator(map_len);
	}
	display_map(map);
	free_map(map);
	return (0);
}
