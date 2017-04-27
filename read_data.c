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

void		read_cmd_room(t_data *data, char **line, int fd)
{
	get_next_line(fd, line);
	
	if (!ft_strncmp(*line, "##start", 7))
		error_lem_in(6);
	else if (!ft_strncmp(*line, "##end", 5))
		error_lem_in(6);
	else if (!ft_strncmp(*line, "#", 1))
		return ;

}	

void		ceck_command_node(t_data *data, char **line, int fd)
{
	if (!ft_strncmp(*line, "##start", 7))
	{
		data->cmd_node = 1;
		if (!data->check_start)
			data->check_start = 1;
		else
			error_lem_in(6);
	}
	else if (!ft_strncmp(*line, "##end", 5))
	{
		data->cmd_node = 2;
		if (!data->check_end)
			data->check_end = 1;
		else
			error_lem_in(6);
	}
	read_cmd_room(data, line, fd);
	ft_printf("data->cmd_node %d\n", data->cmd_node); // verbose
}


int			check_name_room(int c)
{
	if ((' ' < c && c < '-') || ('-' < c && c < 127))
		return (1);
	return (0);
}

int			is_it_room(t_data *data, char *line)
{
	char	*tmp;
	int		limit;

	tmp = line;
	limit = 0;
	while (check_name_room(*tmp))
		tmp++;
	(*tmp != ' ') ? error_lem_in(4) : 0;
	tmp++;
	while (ft_isdigit(*tmp) && limit < 12)
	{
		tmp++;
		limit++;
	}
	(*tmp != ' ') ? error_lem_in(4) : 0;
	tmp++;
	limit = 0;
	while (ft_isdigit(*tmp) && limit < 12)
	{
		tmp++;
		limit++;
	}
	(*tmp != '\0') ? error_lem_in(4) : 0;
	return (1);
}

void		read_rooms(t_data *data, int fd)
{
	char	*line;

	line = NULL;
	while ((get_next_line(fd, &line) > 0))
	{
		if (!ft_strncmp(line, "L", 1))
			error_lem_in(3);
		if (!ft_strncmp(line, "#", 1))
		{
			ceck_command_node(data, &line, fd);
			// continue ;
		}
		if (is_it_room(data, line))
		{

		}
		ft_printf("%s\n", line); // verbose


	}
}

void		read_data(int fd)
{
	t_data	data;

	construct(&data);
	read_n_ants(&data, fd);
	read_rooms(&data, fd);
}
