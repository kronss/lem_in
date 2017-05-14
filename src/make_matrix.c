/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:10:00 by ochayche          #+#    #+#             */
/*   Updated: 2017/05/03 13:10:01 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void		make_matrix(t_data *data, int max)
{
	int i;

	i = -1;
	data->matrix = malloc(sizeof(int *) * max);
	while (++i < max)
	{
		data->matrix[i] = malloc(sizeof(int) * max);
		ft_bzero(data->matrix[i], max * sizeof(int));
	}
}
