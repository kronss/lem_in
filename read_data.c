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



void		push_ants(t_data *data, t_set *set, int *n_ant, int max_ants)
{
	t_node *node;
	int i;
	int max_ways;

	i = 0;
	max_ways = data->max_find_ways;
	node = data->node;
	while (node && (set[i].road[1] != node->id))
		node = node->next;
	printf("L%d-%s ", *n_ant, node->name);
	set[i].ants[1] = *n_ant;
	(*n_ant)++;
	i++;
	while ((i < max_ways) && ((set[i].max - set[0].max) + (i - 1)) < (max_ants - *n_ant))  //
	{
	// while ((i < max_ways) && ((set[i - 1].max < (max_ants - *n_ant))))
	// {
		node = data->node;
		while (node && (set[i].road[1] != node->id))
			node = node->next;
		printf("L%d-%s ", *n_ant, node->name);
		set[i].ants[1] = *n_ant;
		(*n_ant)++;
		i++;
	}
/************************* verbose *****************************/
		int lim, b, a = 0;
		t_set *tmp;
		while (a < data->max_find_ways)
		{
			tmp = &data->set[a];
			lim = tmp->max;
			b = 0;
			printf("road [%d] => ", a);
			while (b < lim)
			{
				printf("-[%d]-", tmp->road[b]);
				b++;
			}
			printf("\n            ");
			b = 0;
			while (b < lim)
			{
				printf("-[%d]-", tmp->ants[b]);
				b++;
			}
			printf("\n");
			++a;
		}
/************************* ****** ******************************/
}



void 		go_ants(t_data *data, int max_ants)
{
	int n_ant;

	n_ant = 1;
	while (n_ant <= max_ants)
	{
		// move_ants ////////////////////////////////////// ???

		push_ants(data, data->set, &n_ant, max_ants);
		printf("\n");
	}
}




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
		printf("\n            ");
		j = 0;
		while (j < lim)
		{
			printf("-[%d]-", tmp->ants[j]);
			j++;
		}
		printf("\n");
		++i;
	}
/***************************************************************/	

	go_ants(data, data->max_ants);

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

