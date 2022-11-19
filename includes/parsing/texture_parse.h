/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture_parse.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 14:47:34 by znajda        #+#    #+#                 */
/*   Updated: 2022/11/19 14:23:44 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_PARSE_H
# define TEXTURE_PARSE_H

# include "initialize_structs.h"
# include "cub3d.h"

char	*texture_parse(char *str);
t_rgba	color_parse(char *str);

#endif
