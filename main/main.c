/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 01:52:42 by llopez            #+#    #+#             */
/*   Updated: 2017/11/25 14:08:25 by mduhoux                                  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/fillit.h"
#include <unistd.h>

int		system(char const *command);

int		main(int argc, char **argv)
{
	char		**map;
	int		*pieces;
	int		x;
	int		y;
	char		**pieces_map;
	int		count_piece;
	int		x_last;
	int		y_last;

	count_piece = 1;
	pieces_map = ft_strsplit(read_file(argv[1]), '\n');
	map = map_generator(pieces_map);
	while (count_piece <= inttab(pieces_map)/4)
	{
		y = inttab(map);
		pieces = read_piece(count_piece, pieces_map);
		while (y >= 0)
		{
			x = ft_strlen(map[0]) - 1;
			while (x >= 0)
			{
				clear_piece(pieces, map);
				if (put_piece(x, y, pieces, map) != NULL)
				{
					x_last = x;
					y_last = y;
				}
				x--;
			}
			y--;
		}
		put_piece(x_last, y_last, pieces, map);
		count_piece++;
	}
	system("clear");
	display_map(map);
	return (0);
}
