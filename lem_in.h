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
** 
** 
** leak
** norm
*/

#ifndef LEM_IN
# define LEM_IN

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>

# include <stdio.h> // dell



/*********** rooms *************/
typedef struct		s_node
{
	char			*name;
	int				cmd;
	int				i;
	int				y;
	int				x;
	struct s_node	*next;
}					t_node;


/************ dynamic roots ussing in recurcion ********/
typedef struct		s_root
{
	int				id;
	struct s_root	*next;
}					t_root;



/************* keep way in id array ************/
typedef struct		s_ways
{
	int				n;
	int				max;
	int				*road;
	struct s_ways	*next;
}					t_ways;




typedef struct		s_data
{
	char 			*line;
	int				max_ants;
	int				cmd_node;
	int				check_start;
	int				check_end;
	int				max;


	int				create_room_permissions; // dell?

	t_node			*node;
	t_root			*root;
	t_ways			*ways;

	int				**matrix;
}					t_data;








void				error_lem_in(int i);
void				read_data(int fd);
void				construct(t_data *data);
void				destruct(t_data *data);
void				read_n_ants(t_data *data, int fd, char **line);
void				is_it_room(t_data *data, char *line);
void				node_push_back(t_data *data, char *line);
void				root_push_back(t_data *data, int id);
void				root_pop(t_data *data);
int					linked_list_len(t_node *tmp);
int					root_listlen(t_root *tmp);
void				make_matrix(t_data *data, int max);
void				read_rooms(t_data *data, int fd, char **line);
void				read_connection(t_data *data, int fd, char **line);


#endif
