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

void		init_add_data(int *visited, int limit)
{
	int i;

	i = -1;
	while (++i < limit)
		visited[i] = 0;
}

void		find_way(int **matrix, int *visited)
{


	if (visited[0] == 1)
		return ;




}










void		build_ways(int **matrix, t_node *node, int limit)
{
	int visited[limit];

	init_add_data(visited, limit);
	printf("======================build_ways===================\n"); // verbose

	for (int i = 0; i < limit; ++i)
		{
			printf("%d--[%d]\n", i, visited[i]);
		}
	for (int k = 0; k < limit; ++k)  // verbose
			{
				for (int l = 0; l < limit; ++l)
				{
					printf(" %d", matrix[k][l]);
				}
				printf("\n");
			}

	

	while (find_way(matrix, visited))
	{




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


	build_ways(&data, data.matrix, data.node, linked_list_len(data.node));

	// destruct(&data);
}































