/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 12:13:36 by ochayche          #+#    #+#             */
/*   Updated: 2017/04/27 12:13:37 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void		construct(t_data *data)
{
	data->line = NULL;
	data->max_ants = 0;
	data->cmd_node = 0;
	data->check_start = 0;
	data->check_end = 0;
	data->max = 0;
	data->max_find_ways = 0;
	data->max_moves = 0;
	data->matrix = NULL;
	data->node = NULL;
	data->root = NULL;
	data->ways = NULL;
	data->set = NULL;
}
