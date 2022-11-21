/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initalize_structs.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 14:15:35 by znajda        #+#    #+#                 */
/*   Updated: 2022/11/19 14:24:55 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "initialize_structs.h"

void	init_checklist(t_checklist *checklist)
{
	checklist->no = 0;
	checklist->so = 0;
	checklist->we = 0;
	checklist->ea = 0;
	checklist->f = 0;
	checklist->c = 0;
}

void	init_readline(t_readline *readline)
{
	readline->line = 0;
	readline->cur_char = 0;
}
