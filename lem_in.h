/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 10:33:33 by ochayche          #+#    #+#             */
/*   Updated: 2017/04/21 10:33:34 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** allowed function:
**  malloc
**  free
**  read
**  write
**  strerror
**  perror
**  exit
*/


/*
** norm check
*/

#ifndef LEM_IN
# define LEM_IN

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>

# include <stdio.h> // dell


typedef struct		s_node
{
	char			*name;
	int				cmd;
	int				i;
	int				y;
	int				x;
	struct s_node	*next;
}					t_node;



typedef struct		s_data
{
	char 			*line;
	int				max_ants;
	int				cmd_node;
	int				check_start;
	int				check_end;

	int				create_room_permissions;

	t_node			*node;
	int				**matrix;
}					t_data;








void				error_lem_in(int i);
void				read_data(int fd);
void				construct(t_data *data);
void				read_n_ants(t_data *data, int fd, char **line);
void				is_it_room(t_data *data, char *line);
void				node_push_back(t_data *data, char *line);
int					linked_list_len(t_node *tmp);
void				make_matrix(t_data *data, int max);
void				read_rooms(t_data *data, int fd, char **line);


#endif
