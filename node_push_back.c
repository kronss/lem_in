/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_push_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 17:37:13 by ochayche          #+#    #+#             */
/*   Updated: 2017/04/28 17:37:14 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		check_duplicate(t_node *node, char *str)
{
	t_node	*tmp;

	tmp = node;

	while (tmp->next)
	{
		if (!ft_strcmp(tmp->name, str))
			error_lem_in(9);
		tmp = tmp->next;
	}
}


t_node		*create_node(t_data *data, char *line)
{
	t_node	*node;
	t_node	*tmp;

	tmp = data->node;

	if (!(node = malloc(sizeof(t_node))))
		error_lem_in(-1);
	node->name = ft_strsub(line, 0, ft_chrposn(line, ' '));
	node->cmd = data->cmd_node;
	if (data->cmd_node)
		data->cmd_node = 0;
	node->next = NULL;
	ft_printf("line---[%s]\n", line);
	ft_printf("name---[%s]\n", node->name);
	ft_printf("cmd----[%d]\n", node->cmd);
	ft_printf("----\n");
	return (node);
}

void		node_push_back(t_data *data, char *line)
{
	t_node *tmp;


	tmp = data->node;
	if (tmp)
	{
		while (tmp->next)
		{
			tmp = tmp->next;
		}		
		tmp->next = create_node(data, line);
		check_duplicate(data->node, tmp->next->name);
	}
	else
	{
		data->node = create_node(data, line);
	}

}
