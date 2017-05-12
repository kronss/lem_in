/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_connection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 09:36:11 by ochayche          #+#    #+#             */
/*   Updated: 2017/05/05 09:36:12 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		check_inselflink(t_data *data, char *line1, char *line2)
{
	while (*line1 != '-' && *line2 != '\0')
	{
		if (*line1 != *line2)
			return ;
		line1++;
		line2++;
	}
	(*line1 == '-' && *line2 == '\0') ? error_lem_in(11, data) : 0;
}

void		check_name_a(t_data *data, t_node *tmp, char *line1, int *a)
{
	while (tmp)
	{
		if (!ft_strcmp(line1, tmp->name))
		{
			*a = tmp->id;
			return ;
		}
		tmp = tmp->next;
	}
	if (*a < 0)
		error_lem_in(12, data);
}

void		check_name_b(t_data *data, t_node *tmp, char *line2, int *b)
{
	while (tmp)
	{
		if (!ft_strcmp(line2, tmp->name))
		{
			*b = tmp->id;
			return ;
		}
		tmp = tmp->next;
	}
	if (*b < 0)
		error_lem_in(12, data);
}

void		check_link(t_data *data, char *line, char *line2)
{
	char 	*line1;
	int		y;
	int		x;

	y = -1;
	x = -1;
	line1 = ft_strsub(line, 0, ft_chrposn(line, '-'));
	check_name_a(data, data->node, line1, &y);
	ft_strdel(&line1);
	check_name_b(data, data->node, line2, &x);
	// printf("a %d\nb %d\n", y, x); // verbose
	
	// printf("data->matrix[y][x] == %d\n", data->matrix[y][x]); // verbose
	if (!data->matrix[y][x] && !data->matrix[x][y])
	{
		data->matrix[y][x] = 1;
		data->matrix[x][y] = 1;
	}
	else
		error_lem_in(13, data);
}

void		read_connection(t_data *data, int fd, char **line)
{
	printf("[%s]\n", *line);  // verbose
	int max = linked_list_len(data->node); // verbose
	check_inselflink(data, *line, ft_strchr(*line, '-') + 1);
	check_link(data, *line, ft_strchr(*line, '-') + 1);





	for (int k = 0; k < max; ++k)  // verbose
		{
			for (int l = 0; l < max; ++l)
			{
				printf(" %d", data->matrix[k][l]);
			}
			printf("\n");
		}

	while ((get_next_line(fd, line) > 0))
	{
		printf("[%s]\n", *line);  // verbose
		if (!ft_strcmp(*line, "##start") || !ft_strcmp(*line, "##end"))
			error_lem_in(6, data);
		else if (!ft_strncmp(*line, "#", 1))
			continue ;
		else if ((ft_chrcount(*line, '-') == 1) && !ft_chrcount(*line, ' '))
		{
			check_inselflink(data, *line, ft_strchr(*line, '-') + 1);
			check_link(data, *line, ft_strchr(*line, '-') + 1);
		}
		else
			error_lem_in(10, data);
		for (int k = 0; k < max; ++k)  // verbose
			{
				for (int l = 0; l < max; ++l)
				{
					printf(" %d", data->matrix[k][l]);
				}
				printf("\n");
			}
	}
	ft_strdel(line);
}
