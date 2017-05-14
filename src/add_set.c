/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 14:33:50 by ochayche          #+#    #+#             */
/*   Updated: 2017/05/14 14:33:51 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void			add_set(t_set *tmp, t_ways *ways)
{
	tmp->id = ways->id;
	tmp->max = ways->max;
	tmp->road = ways->road;
	tmp->ants = (int *)ft_memalloc(ways->max * sizeof(int));
}
