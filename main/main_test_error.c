/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <llopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:54:07 by llopez            #+#    #+#             */
/*   Updated: 2017/11/22 16:17:54 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		i;
	int		lala;
	char	*str;
	char	*iterst;

	i = 0;
	if (argc == 1)
	{
		while (i++ < 44)
		{
			str = ft_strdup("ntoniolo/test_error/t");
			iterst = ft_itoa(i);
			str = ft_strcat(str, iterst);
			lala = check_pieces(read_file(str));
			if (lala == 1)
				printf("OK---------------- t%d\n", i);
			if (lala == -1)
				printf("KO\n");
		}
	}
	else if (argc == 2)
	{
		i = check_pieces(read_file(argv[1]));
		if (i == 1)
			printf("OK---------------- t%d\n", i);
		else if (i == -1)
			printf("KO\n");
	}
	return (0);
}
