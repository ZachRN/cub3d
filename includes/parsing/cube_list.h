/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube_list.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/18 12:27:34 by znajda        #+#    #+#                 */
/*   Updated: 2022/11/18 15:07:11 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_LIST_H
# define CUBE_LIST_H

typedef struct s_list_map
{
	int				line;
	char			*str;
	struct s_list_map *next;
}				t_list_map;

t_list_map *read_map_list(int map_fd);
t_list_map *delete_one_element(t_list_map *to_remove);

#endif