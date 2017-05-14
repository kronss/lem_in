/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_ants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:44:10 by ochayche          #+#    #+#             */
/*   Updated: 2017/05/13 14:44:10 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void		push_ants(t_data *data, t_set *set, int *n_ant, int max_ants)
{
	t_node		*node;
	int			i;
	int			max_ways;

	i = 0;
	max_ways = data->max_find_ways;
	node = data->node;
	while (node && (set[i].road[1] != node->id))
		node = node->next;
	ft_printf(COLOR("L%d-%s "), *n_ant, node->name);
	set[i].ants[1] = *n_ant;
	++(*n_ant);
	++i;
	while ((i < max_ways) &&
	((set[i].max - set[0].max) + (i - 1)) < (max_ants - *n_ant))
	{
		node = data->node;
		while (node && (set[i].road[1] != node->id))
			node = node->next;
		ft_printf(COLOR("L%d-%s "), *n_ant, node->name);
		set[i].ants[1] = *n_ant;
		(*n_ant)++;
		++i;
	}
}

static void		move_ants(t_data *data, t_set *set)
{
	t_node		*node;
	int			i;
	int			*ants;
	int			cur;

	i = 0;
	while (i < data->max_find_ways)
	{
		cur = set[i].max - 2;
		ants = set[i].ants;
		while (0 < cur && cur < (set[i].max - 1))
		{
			if (ants[cur] != 0)
			{
				ants[cur + 1] = ants[cur];
				ants[cur] = 0;
				node = data->node;
				while (node && (set[i].road[cur + 1] != node->id))
					node = node->next;
				ft_printf(COLOR("L%d-%s "), ants[cur + 1], node->name);
			}
			--cur;
		}
		++i;
	}
}

static short	is_any_stuck(t_data *data, t_set *set)
{
	int cur;
	int i;
	int *ants;

	i = 0;
	while (i < data->max_find_ways)
	{
		cur = set[i].max - 2;
		ants = set[i].ants;
		while (0 < cur && cur < (set[i].max - 1))
		{
			if (ants[cur] != 0)
			{
				return (TRUE);
			}
			--cur;
		}
		++i;
	}
	return (FALSE);
}

void			go_ants(t_data *data, int max_ants)
{
	int n_ant;

	n_ant = 1;
	while (n_ant <= max_ants || is_any_stuck(data, data->set))
	{
		move_ants(data, data->set);
		if (0 < n_ant && n_ant <= max_ants)
			push_ants(data, data->set, &n_ant, max_ants);
		ft_printf("\n");
	}
}
