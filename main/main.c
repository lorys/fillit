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

int		system(char const *command);

int		main(int argc, char **argv)
{
	char		**map;
	int		*pieces;
	int		x;
	int		y;
	int		max_try;
	char		**pieces_map;

	x = 0;
	max_try = 30;
	pieces_map = ft_strsplit(read_file(argv[1]), '\n');
	map = map_generator(pieces_map);
	pieces = read_piece(ft_atoi(argv[2]), pieces_map);
	display_map(map);
	ft_putstr("\n------------------------------------\n");
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			system("sleep 1");
			system("clear");
			clear_map(map);
			map[10][5] = '#';
			put_piece(x, y, pieces, map);
			display_map(map);
			x++;
		}
		y++;
	}
	return (0);
}
