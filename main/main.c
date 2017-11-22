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

#include "libft/libft.h"
#include <stdio.h>
#include "fillit.h"



int		main(int argc, char **argv)
{
	int		*tab;
	int		x;
	int		y;
	int		coords_i;

	y = 0;
	tab = read_piece(ft_atoi(argv[2]), ft_strsplit(read_file(argv[1]), '\n'));
	coords_i = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (x == tab[coords_i] && y == tab[coords_i + 1])
			{
				printf("#");
				coords_i += 2;
			}
			else
				printf(".");
			x++;
		}
		y++;
		printf("\n");
	}
	return (0);
}
