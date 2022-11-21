/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube_list.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/18 12:27:14 by znajda        #+#    #+#                 */
/*   Updated: 2022/11/21 14:10:40 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube_list.h"
#include "cub3d_errors.h"
#include "utils.h"

static t_list_map	*list_add_to_end(t_list_map *head, char *str)
{
	t_list_map	*to_add;
	t_list_map	*get_to_end;

	to_add = (t_list_map *)malloc(sizeof(t_list_map));
	if (!to_add)
		two_strings_error(MALLOC_ERROR, "cube_list.c; line 23");
	get_to_end = head;
	while (get_to_end->next)
		get_to_end = get_to_end->next;
	to_add->line = get_to_end->line + 1;
	to_add->str = str;
	to_add->next = NULL;
	return (to_add);
}

void	add_list_to_end(t_list_map *head, t_list_map *tail)
{
	t_list_map	*temp;

	if (!tail)
		return ;
	temp = head;
	while (temp->next)
		temp = temp->next;
	temp->next = tail;
	return ;
}

static t_list_map	*get_all_lines(char *str, int map_fd)
{
	t_list_map	*head;
	t_list_map	*new;

	head = (t_list_map *)malloc(sizeof(t_list_map));
	if (!head)
		two_strings_error(MALLOC_ERROR, "cube_list.c; line 23");
	head->line = 0;
	head->next = NULL;
	head->str = str;
	str = get_next_line(map_fd);
	if (str && str[0] == '\n')
		one_string_error("Newline seperating in the map");
	while (str)
	{
		new = list_add_to_end(head, str);
		add_list_to_end(head, new);
		str = get_next_line(map_fd);
		if (str && str[0] == '\n')
			one_string_error("Newline seperating in the map");
	}
	return (head);
}

t_list_map	*read_map_list(int map_fd)
{
	char		*str;
	t_list_map	*to_hold;

	to_hold = NULL;
	str = get_next_line(map_fd);
	while (str && str[0] == '\n')
	{
		free(str);
		str = get_next_line(map_fd);
	}
	if (!str)
		one_string_error(MAP_ENDED_BEFORE_MAP);
	to_hold = get_all_lines(str, map_fd);
	return (to_hold);
}
