/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root_push_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 12:41:49 by ochayche          #+#    #+#             */
/*   Updated: 2017/05/07 12:41:50 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void		root_pop(t_data *data)
{
	t_root *tmp;
	t_root *tmp2;


	tmp2 = data->root;
	// printf("id :"); // verbose
	// while (tmp2) // verbose
	// {
	// 	printf("-%d", tmp2->id);
	// 	tmp2 = tmp2->next;
	// }
	// printf("\n");
	tmp = data->root;
	// printf("--%p\n", data->root); // verbose
	if (data->root)
	{
		if (data->root->next)
		{
			if (data->root->next->next)
				while (tmp->next->next)
					tmp = tmp->next;
			ft_memdel((void **)&tmp->next);		
		}
		else
			ft_memdel((void **)&data->root);
	}
	
}



t_root		*create_root(t_data *data, int id)
{
	t_root	*root;

	if (!(root = malloc(sizeof(t_root))))
		error_lem_in(-1, data);
	root->id = id;

	root->next = NULL;
	return (root);
}


void		root_push_back(t_data *data, int id)
{
	t_root *tmp;


	tmp = data->root;
	// printf("--%p\n", data->root); // verbose
	if (tmp)
	{
		while (tmp->next)
		{
			tmp = tmp->next;
		}		
		tmp->next = create_root(data, id);
	}
	else
	{
		data->root = create_root(data, id);
	}
	// printf("--%p\n", data->root); // verbose

}
