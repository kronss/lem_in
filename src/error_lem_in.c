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

#define E "ERROR: "

#include "../lem_in.h"

void		error_lem_in(int i, t_data *data)
{
	(i == 1) ? printf(E"file doesn't exist\n") : 0;
	
	/*****   N ants    ******/
	(i == 2) ? printf(E"wrong line in N_ANTS\n") : 0;
	(i == 22) ? printf(E"unexpected command in this block\n") : 0;


	/****** rooms block *****/
	(i == 3) ? printf(E"unexpected char in this block\n") : 0;
	(i == 4) ? printf(E"wrong line in rooms block\n") : 0;
	(i == 5) ? printf(E"MAX_MIN INT\n") : 0;
	(i == 6) ? printf(E"double declarede command ##start or ##end\n") : 0;
	(i == 7) ? printf(E"expected a room after declarede ##start or ##end\n") : 0;
	(i == 8) ? printf(E"invalid data\n") : 0;
	(i == 9) ? printf(E"duplicate was found\n") : 0;
	(i == 90) ? printf(E"no start_room\n") : 0;
	(i == 91) ? printf(E"no end_room\n") : 0;
	
	/******  link block *******/
	(i == 10) ? printf(E"invalid data in link block\n") : 0;
	(i == 11) ? printf(E"inself link\n") : 0;
	(i == 12) ? printf(E"wrong link name\n") : 0;
	(i == 13) ? printf(E"duplicate link\n") : 0;






	(i == 14) ? printf("ERROR\n") : 0;


	(i == -1) ? printf(E"malloc doesn't work\n") : 0;
	__destruct(data);
	exit(1);
}
