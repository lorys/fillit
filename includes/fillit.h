/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <llopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 02:02:58 by llopez            #+#    #+#             */
/*   Updated: 2017/11/22 15:57:10 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 5

typedef	struct	s_int
{
	int			i;
	int			lenght;
	int			height;
	int			diez;
	int			max_tetrimino;
	int			diez_counter;
	int			diez_max;
}				t_int;
char			**map_generator(char **map);
char			*read_file(char *filepath);
int				*read_piece(int i, char **map);
int				check_pieces(char *content);

#endif
