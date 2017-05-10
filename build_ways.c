/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ways.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 12:12:37 by ochayche          #+#    #+#             */
/*   Updated: 2017/05/08 12:12:38 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ways		*make_way(t_data *data, t_root *root, int max) //, t_ways *prev)
{
	t_ways *new;
	static int n = 1;
	int i;

	if (!(new = malloc(sizeof(t_ways))))
		error_lem_in(-1, data);
	if (!(new->road = ft_memalloc(max * sizeof(int))))
		error_lem_in(-1, data);
	i = 0;
	new->id = ++n;
	new->use = 0;
	new->max = max;
	while (root && i < max)
	{
		new->road[i] = root->id;
		i++;
		root = root->next;
	}
	new->next = NULL;
	// new->prev = prev;
	return (new);
}

void		make_ways(t_data *data)
{
	t_ways *tmp;
	int max;

	max = root_listlen(data->root);
	int n = 0;
	tmp = data->ways;
	if (data->ways)
	{
		while (tmp->next)
			tmp = tmp->next;


		tmp->next = make_way(data, data->root, max); //, tmp);
		


	}
	else
	{
		data->ways = make_way(data, data->root, max); //, NULL);
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
	// printf("dfs======recursion======\n"); // verbose
	// printf("id %d\n", id); // verbose
	// for (int l = 0; l < limit; ++l) // verbose
	// 	{
	// 		printf(" %d", data->matrix[id][l]); // verbose
	// 	}
	// printf("\n"); // verbose


	/* visit room */
	if (visited[id] != 1)
	{
		root_push_back(data, id);
		visited[id] = 1;
	}

	// printf("visit===============\n"); // verbose
	// for (int z = 0; z < limit; ++z) // verbose 
	// 	{
	// 		printf("%d--[%d]\n", z, visited[z]);
	// 	}
	// printf("====================\n"); // verbose
	while (id != 0 && ++i < limit)
	{
		if (data->matrix[id][i] == 1 && visited[i] != 1)
		{
			dfs(data, i, visited, limit);
		}
	}

	if (id == 0)
		make_ways(data);

	if (visited[id] == 1)
	{
		root_pop(data);
		visited[id] = 0;
	}

}

void		build_ways(t_data *data, int **matrix, t_node *node, int limit)
{
	int visited[limit];

	ft_bzero(visited, limit * sizeof(int));
	// printf("======================build_ways===================\n"); // verbose

	// for (int i = 0; i < limit; ++i) // verbose 
	// 	{
	// 		printf("%d--[%d]\n", i, visited[i]);
	// 	}
	// for (int k = 0; k < limit; ++k)  // verbose
	// 		{
	// 			for (int l = 0; l < limit; ++l)
	// 			{
	// 				printf(" %d", matrix[k][l]);
	// 			}
	// 			printf("\n");
	// 		}
	// printf("\n");		
	

	// for (int d = 0; d < limit; ++d) // verbose 
	// 	{
	// 		printf("%d--[%d]\n", d, visited[d]);
	// 	}

	dfs(data, 1, visited, limit);
	if (!data->ways)
		error_lem_in(14, data);



	int n = 0;  /* verbose */
	t_ways *tmp;
	tmp = data->ways;
	printf("\n");
	while (tmp)
	{
		// printf("way # %d   ", tmp->n);
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