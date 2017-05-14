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

void		build_data_ways(t_data *data, int **matrix, t_node *node, int max)
{
	build_ways(data, matrix, node, max);
	sort_ways(data, &data->ways);
	choose_roads(data, data->ways, max);
	go_ants(data, data->max_ants);
}

void		read_data(int fd)
{
	t_data	data;

	__construct(&data);
	read_n_ants(&data, fd, &data.line);
	data.max_ants <= 0 ? error_lem_in(2, &data) : 0;
	read_rooms(&data, fd, &data.line);
	data.max = linked_list_len(data.node);
	make_matrix(&data, data.max);

	// t_node *tmp;
	// tmp = data.node;
	// while (tmp)
	// {
	// 	printf("%s\n", tmp->name);
	// 	printf("%d\n", tmp->id);
	// 	printf("__________________\n");
	// 	tmp = tmp->next;
	// }

	read_connection(&data, fd, &data.line);
	build_data_ways(&data, data.matrix, data.node, data.max);
	__destruct(&data);
}


















