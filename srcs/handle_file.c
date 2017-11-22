/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <llopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 10:53:21 by llopez            #+#    #+#             */
/*   Updated: 2017/11/22 16:06:04 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*read_file(char *filepath)
{
	int		fd;
	char	*buf;
	char	*file;
	int		read_i;
	int		toalloc;

	file = (char *)malloc(sizeof(char));
	fd = open(filepath, O_RDONLY);
	buf = (char *)malloc(sizeof(char) * BUF_SIZE + 1);
	toalloc = 0;
	file[0] = '\0';
	if (fd == -1)
		return (NULL);
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
