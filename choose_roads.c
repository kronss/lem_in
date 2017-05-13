/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_roads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 19:40:59 by ochayche          #+#    #+#             */
/*   Updated: 2017/05/10 19:40:59 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			note_visited_rooms(t_data *data, t_ways *ways, int *visited, int *road)
{
	int			max;
	int			i;
	int			n;

	i = 0;
	max = ways->max;
	while (i < max)
	{

		n = road[i];
		// printf("node is == %d\n", n);
		if (n != 0 && n != 1 && visited[n] == 1)
		{
			return (0);
		}	
		++i;
	}
	i = 0;
	while (i < max)
	{
		visited[road[i]] = 1;
		++i;
	}
/********************************* verbose ***********************************/
	// i = 0;
	// while (i < data->max)
	// {
	// 	printf("%d - [%d]\n", i, visited[i]);
	// 	++i;
	// }
	// printf("===out from perebor===\n");
/******************************************************************************/
	return (1);
}

void		create_set(t_data *data, t_ways *ways, int *visited, int res)
{
	int i;
	t_set *tmp;

	printf("====================================== create_set ==========================\n");
	i = 0;
	if (data->set) // && check_max_steps(data)) //////////////////------------------------dick
	{
		printf("delllllllllll =========================\n");
		ft_memdel((void **)&data->set);
	}
	bzero(visited, sizeof(int) * data->max);
	if (!(data->set = malloc(sizeof(t_set) * res + 1)))
		error_lem_in(-1, data);
	while (ways)
	{
		if (note_visited_rooms(data, ways, visited, ways->road))
		{
			tmp = &data->set[i];
			tmp->id = ways->id;
			tmp->max = ways->max;
			tmp->road = ways->road;
			tmp->ants = (int *)ft_memalloc(ways->max * sizeof(int));
			++i;
			data->max_moves += ways->max;
		}
		ways = ways->next;
	}
	data->max_find_ways = res;
	data->max_moves = (data->max_ants + (data->max_moves - res)) / res;  ////
}


int			find_roads(t_data *data, t_ways *ways, int *visited)
{
	int		max;
	int		res;

	res = 0;
	while (ways)
	{
		max = ways->max;
		res += note_visited_rooms(data, ways, visited, ways->road);
		ways = ways->next;
	}
	return (res);
}

void		choose_roads(t_data *data, t_ways *ways, int max)
{
	int visited[max];
	int res;
	
	while (ways)
	{
		bzero(visited, sizeof(int) * max);
		res = find_roads(data, ways, visited);
		
		if (res > data->max_find_ways)  ///////////////////////////////////////////////////////////////////
		{
			create_set(data, ways, visited, res);// make bigger;
			
		}

/********************************* verbose ***********************************/
	// static int n = -1;
	// int i;
	// i = 0;
	// printf(" %d  variant done  ================> next way\n", ++n);
	// while (i < data->max)
	// {
	// 	printf("%d - [%d]\n", i, visited[i]);
	// 	i++;
	// }
	// printf("======\n");
/******************************************************************************/
		ways = ways->next;
	}
}














