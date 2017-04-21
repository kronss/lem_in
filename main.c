/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 21:57:08 by ochayche          #+#    #+#             */
/*   Updated: 2017/04/19 21:57:09 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	usage(void)
{
	ft_printf("usage: ./lem_in [-f file]\n");
	exit(1);
}

void		__construct(t_data *data, char **line)
{
	*line = NULL;
	data->n_ants = 0;
}

void		read_n_ants(t_data *data, int fd, char **line)
{
	char	*tmp;

	get_next_line(fd, line);
	ft_printf("%s\n", *line);

	tmp = *line;
	while (ft_isdigit(*tmp))
		tmp++;
	if ()
}

void		read_data(int fd)
{
	char	*line;
	t_data	data;

	__construct(&data, &line);
	read_n_ants(&data, fd, &line);
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
				error_lem_in(1);
			else
				read_data(fd);
		}
		else
			usage();
	}
	else
		usage();
	return (0);
}
