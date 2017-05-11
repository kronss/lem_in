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



void		build_data_ways(t_data *data, int **matrix, t_node *node, int max)
{
	build_ways(data, matrix, node, max);
	sort_ways(data, &data->ways);
	choose_roads(data, data->ways, max);


	

	






/************************* verbose *****************************/
	int lim, j, i = 0;
	t_set *tmp;
	while (i < data->max_find_ways)
	{
		tmp = &data->set[i];
		lim = tmp->max;
		j = 0;
		printf("road [%d] => ", i);
		while (j < lim)
		{
			printf("-[%d]-", tmp->road[j]);
			j++;
		}
		printf("\n");
		++i;
	}
}

void		read_data(int fd)
{
	t_data	data; 

	__construct(&data);
	read_n_ants(&data, fd, &data.line);
	read_rooms(&data, fd, &data.line);
	data.max = linked_list_len(data.node);
	make_matrix(&data, data.max);
	read_connection(&data, fd, &data.line);
	build_data_ways(&data, data.matrix, data.node, data.max);
	__destruct(&data);
}
