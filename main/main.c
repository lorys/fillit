/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 01:52:42 by llopez            #+#    #+#             */
/*   Updated: 2017/11/24 17:28:52 by mduhoux                                  */
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

	count_piece = 1;
	pieces_map = ft_strsplit(read_file(argv[1]), '\n');
	map = map_generator(pieces_map);
	display_map(map);
	ft_putstr("\n------------------------------------\n");
	while (count_piece < inttab(pieces_map)/4)
	{
		x = 0;
		y = 0;
		pieces = read_piece(count_piece, pieces_map);
		while (y + 1 < inttab(map) && y <= (inttab(map) - pieces[10]))
		{
			x = 0;
			while (map[y][x] != '\0' && x <= ft_strlen(map[y]) - pieces[9])
			{
				usleep(100000);
				system("clear");
				clear_piece(pieces, map);
				if (put_piece(x, y, pieces, map) == NULL)
					usleep(2000000);
				display_map(map);
				printf("x : %d\ny : %d\ntabmap : %d\n", x, y, inttab(map));
				printf("max_y : %d\nmax_x : %d\n", (pieces[10]), (pieces[9]));
				x++;
			}
			y++;
		}
		count_piece++;
	}
	return (0);
}
