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

#include "lem_in.h"

void		construct(t_data *data)
{
	data->max_ants = 0;
	data->cmd_node = FALSE;
	data->create_room_permissions = TRUE;
}
