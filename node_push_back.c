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

// #include <stdio.h>

int			ft_chrposn(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] == c)
			return (i);
	return (0);
}

t_node		*create_node(t_data *data, char *line)
{
	t_node	*node;

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
			tmp->next = tmp;	
		tmp->next = create_node(data, line);

	}
	else
	{
		tmp = create_node(data, line);
	}

}


// int main(int argc, char const *argv[])
// {
// 	char *str = "abcd ef";
// 	char c = ' ';


// 	// char *tmp = ft_strchr(str, c);



// 	printf("-- %d\n", ft_chrposn(str, c));
// 	return 0;
// }
