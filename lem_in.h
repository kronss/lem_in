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
** test1 - segfoult
** leaks
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
	// int				cmd;
	int				id;
	int				y;
	int				x;
	struct s_node	*next;
}					t_node;


/************ dynamic roots useing in recurcion ********/
/************ using only in building ways step *********/
typedef struct		s_root
{
	int				id;
	struct s_root	*next;
}					t_root;






/************* keep way in id array ************/
typedef struct		s_ways
{
	int				id;
	int 			use;
	int				max;
	int				*road;
	struct s_ways	*next;
}					t_ways;





/***************** set of roads ****************** */
typedef struct		s_set
{
	int				id;
	int 			use;
	int				max;
	int				*road;
	int				*ants;

}					t_set;

typedef struct		s_data
{
	char 			*line;
	int				max_ants;
	int				cmd_node;
	int				check_start;
	int				check_end;
	int				max;
	int				max_find_ways;
	int				max_moves;
	

	t_node			*node;
	t_root			*root;
	t_ways			*ways;
	t_set			*set;

	
	int				**matrix;
}					t_data;








void				error_lem_in(int i, t_data *data);
void				read_data(int fd);
void				__construct(t_data *data);
void				__destruct(t_data *data);
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
void				build_ways(t_data *data, int **matrix, t_node *node, int limit);
void				sort_ways(t_data *data, t_ways **head);
void				choose_roads(t_data *data, t_ways *ways, int max);
void		 		go_ants(t_data *data, int max_ants);




#endif














