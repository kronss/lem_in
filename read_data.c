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


void		dfs(t_data *data, int j, int *visited, int limit)
{
	int 	i;

	i = 0;
	// printf("======recursion======\n"); // verbose
	// for (int k = 0; k < limit; ++k)  // verbose
			{
				for (int l = 0; l < limit; ++l)
				{
					printf(" %d", data->matrix[k][l]);
				}
				printf("\n");
			}
	
	if (j == 0)
	{

	}

	while (i < limit)
	{
		if (matrix[j][i] == 1)
		{
			dfs(data, i, visited, limit);
		}



	}



}



void		build_ways(t_data *data, int **matrix, t_node *node, int limit)
{
	int visited[limit];

	ft_bzero(visited, limit * 4);
	printf("======================build_ways===================\n"); // verbose

	for (int i = 0; i < limit; ++i) // verbose 
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

	



	dfs(data, 1, visited, limit);
	

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































