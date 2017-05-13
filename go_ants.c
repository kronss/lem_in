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

}



void		move_ants(t_data *data, t_set *set)
{
	t_node *node;
	int max;
	int i;
	int *ants;
	int cur;

	i = 0;
	while (i < data->max_find_ways)
	{
		cur = set[i].max - 2; // set a position of cur_ant between (start_room + 1) < and (end_room)
		ants = set[i].ants;
		// printf("cur == %d\n", cur);
		while (0 < cur && cur < (set[i].max - 1) ) //&& set[i].ants[cur] != 0)
		{
			if (ants[cur] != 0)
			{
				ants[cur + 1] = ants[cur];
				ants[cur] = 0;

			node = data->node;
			while (node && (set[i].road[cur + 1] != node->id))
				node = node->next;
			printf("L%d-%s ", ants[cur + 1], node->name);
			}
			--cur;
		}
		++i;
	}
}

short		is_any_stuck(t_data *data, t_set *set)
{
	int cur;
	int i;
	int *ants;

	i = 0;
	while (i < data->max_find_ways)
	{
		cur = set[i].max - 2;
		ants = set[i].ants;
		while (0 < cur && cur < (set[i].max - 1) )
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

void 		go_ants(t_data *data, int max_ants)
{
	int n_ant;

	n_ant = 1;
	while (n_ant <= max_ants || is_any_stuck(data, data->set))
	{
		move_ants(data, data->set);
		if (n_ant <= max_ants)
			push_ants(data, data->set, &n_ant, max_ants);
		printf("\n");

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
printf("\n");
	}
}















