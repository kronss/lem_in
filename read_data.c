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

void		construct(t_data *data)
{
	data->max_ants = 0;
	data->cmd_node = FALSE;
	data->create_room_permissions = TRUE;
}

void		read_n_ants(t_data *data, int fd)
{
	char	*line;
	char	*tmp;

	line = NULL;
	get_next_line(fd, &line);
	ft_printf("read: %s\n", line); // verbose

	tmp = line;
	while (ft_isdigit(*tmp))
		tmp++;
	if (*tmp != '\0' || !(data->max_ants = ft_atoi(line)))
		error_lem_in(2);
	ft_printf("data->max_ants: %d\n", data->max_ants); // verbose
}

void		read_command(t_data *data, char *line)
{

}

void		read_rooms(t_data *data, int fd)
{
	char	*line;

	line = NULL;
	while ((get_next_line(fd, &line) > 0))
	{
		if (strncmp(line, "#", 1))
			read_command(data, line);
			
	}


}

void		read_data(int fd)
{
	t_data	data;

	construct(&data);
	read_n_ants(&data, fd);
	read_rooms(&data, fd);
}
