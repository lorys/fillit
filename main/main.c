/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 01:52:42 by llopez            #+#    #+#             */
/*   Updated: 2017/11/26 10:36:24 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/fillit.h"
#include <unistd.h>

int		system(char const *command);

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
	while (find_pieces(count, map) == 1  && count <= (inttab(pieces_map)/4))
		count++;
	if (count == (inttab(pieces_map)/4)+1)
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
			usleep(250000);
			system("clear");
			display_map(map);
			clear_piece(pieces, map);
			if (put_piece(x, y, pieces, map) != NULL && \
				solver(pieces_map, map, count_pieces + 1))
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

	pieces_map = ft_strsplit(read_file(argv[1]), '\n');
	map = map_generator(pieces_map);
	solver(pieces_map, map, 1);
	display_map(map);
	return (0);
}
