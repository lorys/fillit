/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 01:52:42 by llopez            #+#    #+#             */
/*   Updated: 2017/11/22 10:06:09 by llopez           ###   ########.fr       */
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

	x = 0;
	y = 0;
	max_try = 30;
	map = map_generator(ft_strsplit(read_file(argv[1]), '\n'));
	pieces = read_piece(1, map);
	display_map(map);
	ft_putstr("\n------------------------------------\n");
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{
			put_piece(5, 8, pieces, map);
			display_map(map);
			x++;
		}
		y++;
	}
	return (0);
}
