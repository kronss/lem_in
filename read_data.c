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

int				linked_list_len(t_node *tmp)
{
	int i;

	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}


void		read_cmd_room(t_data *data, int fd, char **line)
{
	get_next_line(fd, line);
	// if (!ft_strncmp(*line, "##start", 7))
	// 	error_lem_in(6);
	// else if (!ft_strncmp(*line, "##end", 5))
	// 	error_lem_in(6);
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
	else if (!ft_strncmp(*line, "#", 1))
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
}


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



int			check_name_cnct(char *line1, char c, char *line2)
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
	

	while ((get_next_line(fd, line) > 0))
	{
		if ((ft_chrcount(*line, '-') == 1) && !ft_chrcount(*line, ' '))
		{
			check_inselflink(*line, ft_strchr(*line, '-') + 1);

			check_name_cnct();
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
	// make_matrix(&data);
	read_connection(&data, fd, &data.line);
}







