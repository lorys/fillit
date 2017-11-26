/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 07:44:32 by maduhoux          #+#    #+#             */
/*   Updated: 2017/11/26 16:52:16 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdlib.h>

static int		diez_finder(char *content, int i, int x, int y)
{
	int max;

	max = 0;
	if (content[i - 1] == '#' && x > 0)
		max++;
	if (content[i - 5] == '#' && y > 0)
		max++;
	if (content[i + 1] == '#' && x < 4)
		max++;
	if (content[i + 5] == '#' && y < 4)
		max++;
	if (max > 0)
		return (max);
	return (-1);
}

static int		checker_tetrimino(t_int *lst, char *content)
{
	while ((content[lst->i] == '.' || content[lst->i] == '#'))
	{
		if (content[lst->i] == '#')
		{
			lst->diez_counter = diez_finder(content, lst->i, lst->length, \
				lst->height);
			if (lst->diez_counter == -1)
				return (-1);
			if (lst->diez_counter > lst->diez_max)
				lst->diez_max = lst->diez_counter;
			lst->diez++;
		}
		lst->length++;
		lst->i++;
	}
	if (lst->length != 4)
		return (-1);
	if (lst->length == 4 && content[lst->length] == '\n')
	{
		lst->height++;
		lst->i++;
		lst->length = 0;
	}
	return (0);
}

static int		checker_error(t_int *lst, char *content)
{
	if (lst->diez != 4 || lst->height != 4)
		return (-1);
	lst->max_tetrimino++;
	if (content[lst->height] != '\n')
		return (-1);
	if (lst->max_tetrimino > 26)
		return (-1);
	if (content[lst->i] == '\n' && content[lst->i + 1] == '\0')
		return (-1);
	if (lst->diez_max < 2)
		return (-1);
	return (0);
}

static int		checker_while(t_int *lst, char *content)
{
	lst->diez_counter = 0;
	lst->diez_max = 0;
	while (content[lst->i] != '\n' && content[lst->i + 1] != '\0' && \
	content[lst->i + 1] != '\n')
	{
		if (checker_tetrimino(lst, content) == -1)
			return (-1);
	}
	if (checker_error(lst, content) == -1)
		return (-1);
	else
	{
		lst->height = 0;
		lst->diez = 0;
	}
	return (0);
}

int				check_pieces(char *content)
{
	t_int	lst;

	lst.i = 0;
	lst.length = 0;
	lst.height = 0;
	lst.max_tetrimino = 0;
	lst.diez = 0;
	if (!*content)
		return (-1);
	while (content[lst.i] != '\0')
	{
		if (checker_while(&lst, content) == -1)
			return (-1);
		lst.i++;
	}
	return (1);
}
