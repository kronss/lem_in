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

#include "../lem_in.h"

static int		note_visited_rooms(t_ways *ways, int *visited, int *road)
{
	int			max;
	int			i;
	int			n;

	i = 0;
	max = ways->max;
	while (i < max)
	{
		n = road[i];
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
	return (1);
}

static int		check_max_steps(t_data *data, t_ways *ways, int *vis, int res)
{
	int			tmp;
	int			control;

	tmp = 0;
	bzero(vis, sizeof(int) * data->max);
	while (ways)
	{
		if (note_visited_rooms(ways, vis, ways->road))
		{
			tmp += ways->max;
		}
		ways = ways->next;
	}
	control = (data->max_ants + (tmp - res)) / res;
	if (control >= data->max_moves)
		return (1);
	return (0);
}

static void		create_set(t_data *data, t_ways *ways, int *visited, int res)
{
	int			i;

	i = -1;
	if (data->set)
	{
		if (check_max_steps(data, ways, visited, res))
			return ;
		del_set(&data->set, data->max_find_ways);
	}
	bzero(visited, sizeof(int) * data->max);
	if (!(data->set = malloc(sizeof(t_set) * res + 1)))
		error_lem_in(-1, data);
	while (ways)
	{
		if (note_visited_rooms(ways, visited, ways->road))
		{
			add_set(&data->set[++i], ways);
			data->max_moves += ways->max;
		}
		ways = ways->next;
	}
	data->max_find_ways = res;
	data->max_moves = (data->max_ants + (data->max_moves - res)) / res;
}

static int		find_roads(t_ways *ways, int *visited)
{
	int			max;
	int			res;

	res = 0;
	while (ways)
	{
		max = ways->max;
		res += note_visited_rooms(ways, visited, ways->road);
		ways = ways->next;
	}
	return (res);
}

void			choose_roads(t_data *data, t_ways *ways, int max)
{
	int			visited[max];
	int			res;

	while (ways)
	{
		bzero(visited, sizeof(int) * max);
		res = find_roads(ways, visited);
		if (res > data->max_find_ways)
		{
			create_set(data, ways, visited, res);
		}
		ways = ways->next;
	}
}
