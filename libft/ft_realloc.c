/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 21:52:07 by llopez            #+#    #+#             */
/*   Updated: 2017/11/29 15:23:48 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_realloc(char *src, size_t new_size)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	ft_strcpy(tmp, src);
	free(src);
	if (!(src = (char *)malloc(sizeof(char) * new_size)))
		return (NULL);
	src[new_size - 1] = '\0';
	ft_strcpy(src, tmp);
	return (src);
}
