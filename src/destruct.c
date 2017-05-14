/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 11:12:54 by ochayche          #+#    #+#             */
/*   Updated: 2017/05/08 11:12:55 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void		del_node(t_node **head)
{
	if (*head)
	{
		del_node(&(*head)->next);
		ft_strdel(&(*head)->name);
		ft_memdel((void **)head);
	}
}

static void		del_root(t_root **head)
{
	if (*head)
	{
		del_root(&(*head)->next);
		ft_memdel((void **)head);
	}
}

static void		del_ways(t_ways **head)
{
	if (*head)
	{
		del_ways(&(*head)->next);
		ft_memdel((void **)&(*head)->road);
		ft_memdel((void **)head);
	}
}

void			del_set(t_set **head, int lim)
{
	int			i;
	t_set		*tmp;

	i = 0;
	tmp = *head;
	while (i < lim)
	{
		ft_memdel((void **)&tmp[i].ants);
		++i;
	}
	ft_memdel((void **)head);
}

void			destruct(t_data *data)
{
	int			i;

	if (!data)
		return ;
	i = -1;
	ft_strdel(&data->line);
	del_node(&data->node);
	del_root(&data->root);
	while (++i < data->max && data->matrix)
	{
		ft_memdel((void **)&data->matrix[i]);
	}
	ft_memdel((void **)&data->matrix);
	del_ways(&data->ways);
	del_set(&data->set, data->max_find_ways);
}
