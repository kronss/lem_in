/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __destruct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 11:12:54 by ochayche          #+#    #+#             */
/*   Updated: 2017/05/08 11:12:55 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void		del_node(t_node **head)
{
	if (*head)
	{
 		del_node(&(*head)->next);
		ft_strdel(&(*head)->name);
		ft_memdel((void **)head);
	}
}

void		del_root(t_root **head)
{
	if (*head)
	{
 		del_root(&(*head)->next);
		ft_memdel((void **)head);
	}
}

void		del_ways(t_ways **head)
{
	if (*head)
	{
 		del_ways(&(*head)->next);
		ft_memdel((void **)&(*head)->road);
		ft_memdel((void **)head);
	}
}

void		del_set(t_set **head, int lim)
{
	t_set *tmp;
	int i;

	i = 0;
	tmp = *head;

	while (i < lim)
	{
		ft_memdel((void **)&tmp[i].ants);
		// ft_memdel((void **)tmp[i].road);
		++i;
	}
	ft_memdel((void **)head);
}

void		__destruct(t_data *data)
{
	int j;
	int i;

	j = 0;
	i = 0;
	printf("====================destruct\n");
	ft_strdel(&data->line);
	// data->max_ants = 0;
	// data->cmd_node = 0;
	// data->check_start = 0;
	// data->check_end = 0;
	// data->create_room_permissions = TRUE; //
	del_node(&data->node);
	del_root(&data->root);
	while (j < data->max && data->matrix)
	{
		ft_memdel((void **)&data->matrix[j]);
		// free(data->matrix[j]);
		j++;
		// printf("====================destruct\n");
	}
	ft_memdel((void **)&data->matrix);
	del_ways(&data->ways);
	del_set(&data->set, data->max_find_ways);
	// data->node = NULL;
	// data->root = NULL;
	// data->ways = NULL;
}
