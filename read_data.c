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

t_ways		*make_road(t_root *root, int max)
{
	t_ways *new;
	static int n = -1;
	int i;

	if (!(new = malloc(sizeof(t_ways))))
		error_lem_in(-1);
	if (!(new->road = ft_memalloc(max * 4)))
		error_lem_in(-1);
	i = 0;
	new->n = ++n;
	new->max = max;
	while (root && i < max)
	{
		new->road[i] = root->id;
		i++;
		root = root->next;
	}
	new->next = NULL;
	return (new);
}

void		make_root(t_data *data)
{
	t_ways *tmp;
	int max;

	max = root_listlen(data->root);
	printf("======================================root_listlen==================%d\n", max);
	int n = 0;
	tmp = data->ways;
	if (data->ways)
	{
		while (tmp->next)
			tmp = tmp->next;


		tmp->next = make_road(data->root, max);
		


		while (n < max)  // verbose
		{
			printf("-[%d]-",tmp->road[n]);
			n++;
		}



	}
	else
	{
		data->ways = make_road(data->root, max);
		while (n < max) // verbose
		{
			printf("-[%d]-",data->ways->road[n]);
			n++;
		}
	}



	
	printf("\n");
}


void		dfs(t_data *data, int id, int *visited, int limit)
{
	int 	i;

	i = -1;
	printf("dfs======recursion======\n"); // verbose
	printf("id %d\n", id); // verbose
	for (int l = 0; l < limit; ++l) // verbose
		{
			printf(" %d", data->matrix[id][l]); // verbose
		}
	printf("\n"); // verbose


	/* visit room */
	if (visited[id] != 1)
	{
		root_push_back(data, id);
		visited[id] = 1;
	}

	printf("visit===============\n"); // verbose
	for (int z = 0; z < limit; ++z) // verbose 
		{
			printf("%d--[%d]\n", z, visited[z]);
		}
	printf("====================\n"); // verbose
	while (id != 0 && ++i < limit)
	{
		if (data->matrix[id][i] == 1 && visited[i] != 1)
		{
			dfs(data, i, visited, limit);
		}
	}

	if (id == 0)
		make_root(data);

	if (visited[id] == 1)
	{
		root_pop(data);
		visited[id] = 0;
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
	printf("\n");		
	

	for (int d = 0; d < limit; ++d) // verbose 
		{
			printf("%d--[%d]\n", d, visited[d]);
		}

	dfs(data, 1, visited, limit);
	



	int n = 0;  /* verbose */
	t_ways *tmp;
	tmp = data->ways;
	printf("\n");
	while (tmp)
	{
		printf("way # %d   ", tmp->n);
		n = 0;

		while (n < tmp->max)
		{
			printf("-[%d]-",tmp->road[n]);
			n++;
		}
		printf("\n");
		tmp = tmp->next;
	}
}













void		read_data(int fd)
{
	t_data	data; 

	construct(&data);
	read_n_ants(&data, fd, &data.line);
	read_rooms(&data, fd, &data.line);
	data.max = linked_list_len(data.node);
	make_matrix(&data, data.max);

	read_connection(&data, fd, &data.line);


	build_ways(&data, data.matrix, data.node, data.max);



	destruct(&data);
}































