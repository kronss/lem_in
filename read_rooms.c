/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:12:02 by ochayche          #+#    #+#             */
/*   Updated: 2017/05/03 13:12:03 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		check_start_end(t_node *node)
{
	short n;
	short m;

	n = 0;
	m = 0;
	while (node)
	{
		if (node->cmd == 0)
			n++;
		if (node->cmd == 1)
			m++;
		node = node->next;
	}
	n ? 0 : error_lem_in(90);
	m ? 0 : error_lem_in(91);
}


void		read_cmd_room(t_data *data, int fd, char **line)
{
	get_next_line(fd, line);
	if (!ft_strncmp(*line, "#", 1))
		error_lem_in(7);
	else if (!ft_strncmp(*line, "L", 1))
		error_lem_in(3);
	else if ((ft_chrcount(*line, ' ') == 2) && !ft_chrcount(*line, '-'))
	{
		is_it_room(data, *line);
		node_push_back(data, *line);
	}
	else
		error_lem_in(7);
}

void		check_command_node(t_data *data, char **line, int fd)
{
	if (!ft_strcmp(*line, "##start"))
	{
		data->cmd_node = 2;
		if (!data->check_start)
			data->check_start = 1;
		else
			error_lem_in(6);
	}
	else if (!ft_strcmp(*line, "##end"))
	{
		data->cmd_node = 1;
		if (!data->check_end)
			data->check_end = 1;
		else
			error_lem_in(6);
	}
	else
		return ;
	read_cmd_room(data, fd, line);
}

void		read_rooms(t_data *data, int fd, char **line)
{
	while ((get_next_line(fd, line) > 0))
	{
		if (!ft_strncmp(*line, "L", 1))
			error_lem_in(3);
		else if (!ft_strncmp(*line, "#", 1))
		{
			check_command_node(data, line, fd);
		}
		else if ((ft_chrcount(*line, '-') == 1) && !ft_chrcount(*line, ' '))
			break;
		else if ((ft_chrcount(*line, ' ') == 2) && !ft_chrcount(*line, '-')) 
		{
			is_it_room(data, *line);
			node_push_back(data, *line);
		}
		else
			error_lem_in(8);
		// ft_printf("%s\n", *line); // verbose
	}
	check_start_end(data->node);
}
