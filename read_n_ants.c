/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_n_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 22:23:20 by ochayche          #+#    #+#             */
/*   Updated: 2017/04/27 22:23:21 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		read_n_ants(t_data *data, int fd, char **line)
{
	char	*tmp;
	int		lim;
	long	val;

	lim = 1;
	while (get_next_line(fd, line) > 0)
	{
		printf("[%s]\n", *line);  // verbose
		if (!ft_strcmp("##start", *line) || !ft_strcmp("##end", *line))
			error_lem_in (22);
		else if (!ft_strncmp("#", *line, 1))
			continue ;
		else
		{
			val = ft_atol(*line);
			printf("read: %s\n", *line); // verbose
			tmp = *line;
			while (ft_isdigit(*tmp) && lim++ < 11)
				tmp++;
			if (*tmp != '\0' || !(data->max_ants = ft_atoi(*line)))
				error_lem_in(2);
			if (!(0 < val && val <= 2147483647))
				error_lem_in(5);
			printf("data->max_ants: %d\n", data->max_ants); // verbose
			break ;
		}
	}
}
