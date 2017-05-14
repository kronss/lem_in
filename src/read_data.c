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

#include "../lem_in.h"

static void		build_data_ways(t_data *data, int max)
{
	build_ways(data, max);
	sort_ways(&data->ways);
	choose_roads(data, data->ways, max);
	go_ants(data, data->max_ants);
}

void			read_data(int fd)
{
	t_data	data;

	construct(&data);
	read_n_ants(&data, fd, &data.line);
	data.max_ants <= 0 ? error_lem_in(2, &data) : 0;
	read_rooms(&data, fd, &data.line);
	data.max = linked_list_len(data.node);
	make_matrix(&data, data.max);
	read_connection(&data, fd, &data.line);
	build_data_ways(&data, data.max);
	destruct(&data);
}
