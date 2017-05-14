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

#include "../lem_in.h"

static t_ways	*make_way(t_data *data, t_root *root, int max)
{
	int			i;
	t_ways		*new;
	static int	n = 1;

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
	return (new);
}

static void		make_ways(t_data *data)
{
	int			max;
	t_ways		*tmp;

	max = root_listlen(data->root);
	tmp = data->ways;
	if (data->ways)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = make_way(data, data->root, max);
	}
	else
	{
		data->ways = make_way(data, data->root, max);
	}
}

static void		dfs(t_data *data, int id, int *visited, int limit)
{
	int			i;

	i = -1;
	if (visited[id] != 1)
	{
		root_push_back(data, id);
		visited[id] = 1;
	}
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

void			build_ways(t_data *data, int limit)
{
	int			visited[limit];

	ft_bzero(visited, limit * sizeof(int));
	dfs(data, 1, visited, limit);
	if (!data->ways)
		error_lem_in(14, data);
}
