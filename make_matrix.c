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

#include "lem_in.h"

void		make_matrix(t_data *data, int max)
{
	int i;
	int j;
	// int **matrix;

	j = -1;
	// matrix = data->matrix;
	data->matrix = malloc(sizeof(int *) * max);
	while (++j < max)
	{
		data->matrix[j] = malloc(sizeof(int) * max);
		ft_bzero(data->matrix[j], max * 4);
	}

	for (int k = 0; k < max; ++k) // verbose
	{
		for (int l = 0; l < max; ++l)
		{
			printf(" %d", data->matrix[k][l]);
		}
		printf("\n");
	}
}
