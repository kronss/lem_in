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







void		find_roads(t_data *data, t_ways *ways, int *visited, int *road)
{

/********************************* hear **********************/
	int		max;
	int i;

	i = 0;
	max = ways->max;

	while (i < max)
	{
		visited[road[i]] = 1;

		i++;
	}

	while (ways)
	{
		max = ways->max;

		ways = ways->next;
	}	

/********************************* hear **********************/





	// i = 0;
	// while (i < data->max)
	// {
	// 	printf("%d - [%d]\n", i, visited[i]);
	// 	i++;
	// }




	// while (ways)
	// {
	// 	max = ways->max;

	// 	ways = ways->next;
	// }



}

void		choose_roads(t_data *data, t_ways *ways, int max)
{
	int visited[max];




	
	// while (ways)
	// {
		bzero(visited, sizeof(int) * max);
		find_roads(data, ways, visited, ways->road);



	// 	ways = ways->next;
	// }


	






}


void		read_data(int fd)
{
	t_data	data; 

	__construct(&data);
	read_n_ants(&data, fd, &data.line);
	read_rooms(&data, fd, &data.line);
	data.max = linked_list_len(data.node);
	make_matrix(&data, data.max);
	read_connection(&data, fd, &data.line);
	build_ways(&data, data.matrix, data.node, data.max);
	sort_ways(&data, &data.ways);

	choose_roads(&data, data.ways, data.max);






	__destruct(&data);
}































