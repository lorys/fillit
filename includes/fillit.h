/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <llopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 02:02:58 by llopez            #+#    #+#             */
/*   Updated: 2017/11/26 13:06:53 by llopez           ###   ########.fr       */
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
	int			length;
	int			height;
	int			diez;
	int			max_tetrimino;
	int			diez_counter;
	int			diez_max;
}				t_int;
char			**map_generator(int len);
char			*read_file(char *filepath);
int				*read_piece(int i, char **map);
int				check_pieces(char *content);
char				**put_piece(int x, int y, int *piece, char **map);
void				display_map(char **map);
char				**clear_map(char **map);
char				**clear_piece(int *piece, char **map);
int				inttab(char **tab);

#endif
