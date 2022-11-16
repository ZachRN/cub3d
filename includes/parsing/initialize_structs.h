/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_structs.h                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 14:16:20 by znajda        #+#    #+#                 */
/*   Updated: 2022/11/16 14:17:24 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZE_STRUCTS_H
# define INITIALIZE_STRUCTS_H


typedef struct s_checklist
{
	int	NO;
	int	SO;
	int	WE;
	int	EA;
	int	F;
	int	C;
}				t_checklist;

typedef struct s_readline
{
	int			line;
	int			cur_char;
}				t_readline;

void	init_checklist(t_checklist *checklist);
void	init_readline(t_readline *readline);

#endif
