/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 19:55:50 by ochayche          #+#    #+#             */
/*   Updated: 2017/04/25 19:55:50 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		check_inselflink(char *line1, char *line2)
{
	while (*line1 != '-' && *line2 != '\0')
	{
		if (*line1 != *line2)
			return ;
		line1++;
		line2++;
	}
	(*line1 == '-' && *line2 == '\0') ? error_lem_in(11) : 0;
}

int		check_link(char *line1, char *line2)
{
	
	
	while (*line1 == *line2 && *line1 != c && *line2 != '\0')
	{
		line1++;
		line2++;
	}
	if (*line1 == c && *line2 == '\0')
		return (1);
	else
		return (0);
}

void		read_connection(t_data *data, int fd, char **line)
{
	check_inselflink(*line, ft_strchr(*line, '-') + 1);
	check_link(*line, ft_strchr(*line, '-') + 1);




	while ((get_next_line(fd, line) > 0))
	{
		if ((ft_chrcount(*line, '-') == 1) && !ft_chrcount(*line, ' '))
		{
			check_inselflink(*line, ft_strchr(*line, '-') + 1);
			
			check_link();
		}
		else
			error_lem_in(10);
	}
}











void		read_data(int fd)
{
	t_data	data;

	construct(&data);
	read_n_ants(&data, fd, &data.line);
	read_rooms(&data, fd, &data.line);
	make_matrix(&data, linked_list_len(data.node));
	read_connection(&data, fd, &data.line);
}







