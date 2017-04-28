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

int			is_it_room(t_data *data, char *line)
{
	char	*tmp;
	int		limit;

	tmp = line;
	limit = 0;
	while (check_name_room(*tmp))
		tmp++;
	(*tmp != ' ') ? error_lem_in(4) : 0;
	tmp++;
	while (ft_isdigit(*tmp) && limit < 12)
	{
		tmp++;
		limit++;
	}
	(*tmp != ' ') ? error_lem_in(4) : 0;
	tmp++;
	limit = 0;
	while (ft_isdigit(*tmp) && limit < 12)
	{
		tmp++;
		limit++;
	}
	(*tmp != '\0') ? error_lem_in(4) : 0;
	return (1);
}
