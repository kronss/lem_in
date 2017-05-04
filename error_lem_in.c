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
	
	/*****   N ants    ******/
	(i == 2) ? ft_printf(E"wrong line in N_ANTS\n") : 0;
	(i == 22) ? ft_printf(E"unexpected command in this block\n") : 0;


	/****** rooms block *****/
	(i == 3) ? ft_printf(E"unexpected char in this block\n") : 0;
	(i == 4) ? ft_printf(E"wrong line in rooms block\n") : 0;
	(i == 5) ? ft_printf(E"MAX_MIN INT\n") : 0;
	(i == 6) ? ft_printf(E"double declarede command ##start or ##end\n") : 0;
	(i == 7) ? ft_printf(E"expected a room after declarede ##start or ##end\n") : 0;
	(i == 8) ? ft_printf(E"invalid data\n") : 0;
	(i == 9) ? ft_printf(E"duplicate was found\n") : 0;
	


	/******  link block *******/
	(i == 10) ? ft_printf(E"invalid data in link block\n") : 0;
	(i == 11) ? ft_printf(E"inself link\n") : 0;
	(i == 12) ? ft_printf(E"wrong link name\n") : 0;
	(i == 13) ? ft_printf(E"duplicate link\n") : 0;





	(i == -1) ? ft_printf(E"malloc doesn't work\n") : 0;
	exit(1);
}
