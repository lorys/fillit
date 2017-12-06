/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <llopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 10:53:21 by llopez            #+#    #+#             */
/*   Updated: 2017/12/02 17:01:47 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*read_file(char *filepath)
{
	int		fd;
	char	*buf;
	char	*file;
	int		read_i;
	int		toalloc;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (NULL);
	if (!(file = (char *)malloc(sizeof(char))))
		return (NULL);
	if (!(buf = (char *)malloc(sizeof(char) * BUF_SIZE + 1)))
		return (NULL);
	toalloc = 0;
	file[0] = '\0';
	while ((read_i = read(fd, buf, BUF_SIZE)))
	{
		toalloc += read_i;
		buf[read_i] = '\0';
		file = ft_realloc(file, toalloc + 1);
		ft_strcat(file, buf);
	}
	close(fd);
	return (file);
}

int		meanwhile(char **argv)
{
	char		**map;
	char		**pieces_map;
	int			map_len;

	pieces_map = ft_strsplit(read_file(argv[1]), '\n');
	map_len = ft_sqrt(inttab(pieces_map));
	if (!(map = map_generator(map_len)))
	{
		ft_putstr("error\n");
		return (-1);
	}
	while (sherlock(pieces_map, map, 1) == 0)
	{
		map_len++;
		map = map_generator(map_len);
	}
	if (sherlock(pieces_map, map, 1) == -1)
		return (-1);
	display_map(map);
	free_map(map);
	return (0);
}
