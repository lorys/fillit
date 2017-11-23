/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 01:52:42 by llopez            #+#    #+#             */
/*   Updated: 2017/11/23 10:36:10 by llopez           ###   ########.fr       */
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
	x = 0;
	y = 0;
	pieces_map = ft_strsplit(read_file(argv[1]), '\n');
	map = map_generator(pieces_map);
	pieces = read_piece(count_piece, pieces_map);
	display_map(map);
	ft_putstr("\n------------------------------------\n");
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			usleep(200000);
			system("clear");
			clear_piece(pieces, map);
			put_piece(x, y, pieces, map);
			display_map(map);
			x++;
		}
		y++;
	}
	return (0);
}
