/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initalize_structs.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 14:15:35 by znajda        #+#    #+#                 */
/*   Updated: 2022/11/16 14:17:20 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "initialize_structs.h"

void	init_checklist(t_checklist *checklist)
{
	checklist->NO = 0;
	checklist->SO = 0;
	checklist->WE = 0;
	checklist->EA = 0;
	checklist->F = 0;
	checklist->C = 0;
}

void	init_readline(t_readline *readline)
{
	readline->line = 0;
	readline->cur_char = 0;
}