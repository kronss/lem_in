/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ways.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 19:55:50 by ochayche          #+#    #+#             */
/*   Updated: 2017/04/25 19:55:50 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


void		swap_list(t_ways *cur1, t_ways *cur2)
{
	int tmp_max;
	int *tmp_road;

	tmp_max = cur2->max;
	tmp_road = cur2->road;
	cur2->max = cur1->max;
	cur2->road = cur1->road;
	cur1->max = tmp_max;
	cur1->road = tmp_road;
}


void		sort_ways(t_data *data, t_ways **head)
{
	t_ways *cur1;
	t_ways *cur2;

	cur1 = *head;

	while (cur1)
	{
		cur2 = cur1->next;
		while (cur2)
		{
			if (cur1->max > cur2->max)
			{
				swap_list(cur1, cur2);
			}
			cur2 = cur2->next;
		}
		cur1 = cur1->next;
	}
/************************** verbose *************************/
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
