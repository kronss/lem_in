/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 21:57:08 by ochayche          #+#    #+#             */
/*   Updated: 2017/05/05 11:51:07 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	usage(void)
{
	printf("usage: ./lem_in [-f file]\n");
	exit(1);
}

int			main(int ar, char **av)
{
	int	fd;


	if (ar == 1)
	{
		read_data(STDIN);
	}
	else if (ar == 3)
	{
		if (!strcmp("-f", av[1]))
		{
			if ((fd = open(av[2], O_RDONLY)) == -1)
				error_lem_in(1, NULL);
			else
				read_data(fd);
		}
		else
			usage();
	}
	else
		usage();
	// while (1);
	return (0);
}
