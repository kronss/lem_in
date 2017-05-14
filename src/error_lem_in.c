/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_lem_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 11:18:11 by ochayche          #+#    #+#             */
/*   Updated: 2017/04/21 11:18:12 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void		error_lem_in(int i, t_data *data)
{
	(i == 1) ? ft_printf(ERROR) : 0;
	(i == 2) ? ft_printf(ERROR) : 0;
	(i == 22) ? ft_printf(ERROR) : 0;
	(i == 3) ? ft_printf(ERROR) : 0;
	(i == 4) ? ft_printf(ERROR) : 0;
	(i == 5) ? ft_printf(ERROR) : 0;
	(i == 6) ? ft_printf(ERROR) : 0;
	(i == 7) ? ft_printf(ERROR) : 0;
	(i == 8) ? ft_printf(ERROR) : 0;
	(i == 9) ? ft_printf(ERROR) : 0;
	(i == 90) ? ft_printf(ERROR) : 0;
	(i == 91) ? ft_printf(ERROR) : 0;
	(i == 10) ? ft_printf(ERROR) : 0;
	(i == 11) ? ft_printf(ERROR) : 0;
	(i == 12) ? ft_printf(ERROR) : 0;
	(i == 13) ? ft_printf(ERROR) : 0;
	(i == 14) ? ft_printf(ERROR) : 0;
	(i == -1) ? ft_printf(ERROR) : 0;
	destruct(data);
	exit(1);
}
