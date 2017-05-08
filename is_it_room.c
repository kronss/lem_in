/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 17:10:27 by ochayche          #+#    #+#             */
/*   Updated: 2017/04/28 17:10:28 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


static int			check_name_room(int c)
{
	if ((' ' < c && c < '-') || ('-' < c && c < 127))
		return (1);
	return (0);
}

void			is_it_room(t_data *data, char *line)
{
	char	*tmp;
	int		limit;

	limit = 0;
	if (!check_name_room(*line))
		error_lem_in(4, data);
	while (check_name_room(*line))
		line++;
	(*line != ' ') ? error_lem_in(4, data) : 0;
	line++;
	while (ft_isdigit(*line) && limit < 12)
	{
		line++;
		limit++;
	}
	(*line != ' ' || !limit) ? error_lem_in(4, data) : 0;
	line++;
	limit = 0;
	while (ft_isdigit(*line) && limit < 12)
	{
		line++;
		limit++;
	}
	// ft_printf("=====%d\n", limit);
	(*line != '\0' || !limit) ? error_lem_in(4, data) : 0;
}
