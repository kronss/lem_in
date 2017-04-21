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

#ifndef LEM_IN
# define LEM_IN

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>

typedef struct	s_data
{
	int			n_ants;
	
}				t_data;



void		error_lem_in(int i);
void		read_data(int fd);






#endif
