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

#define E  "ERROR: "

#include "lem_in.h"

void		error_lem_in(int i)
{
	(i == 1) ? ft_printf(E"file doesn't exist\n") : 0;
	(i == 2) ? ft_printf(E"wrong line in N_ANTS\n") : 0;
	(i == 3) ? ft_printf(E"unexpected char in this block\n") : 0;
	(i == 4) ? ft_printf(E"wrong line in rooms block\n") : 0;
	(i == 5) ? ft_printf(E"MAX_MIN INT\n") : 0;
	(i == 6) ? ft_printf(E"double declarede comand ##start or ##end\n") : 0;
	exit(1);
}
