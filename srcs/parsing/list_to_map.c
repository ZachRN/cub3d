/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_to_map.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/18 13:27:02 by znajda        #+#    #+#                 */
/*   Updated: 2022/11/19 16:38:41 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_errors.h"
#include "cube_list.h"
#include "utils.h"

#include <stdio.h>

void	is_in_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return ;
		i++;
	}
	one_string_error("Found invalid character within map parsing");
}

t_cubed	determine_player_direction(t_cubed cube, char c)
{
	if (c == 'N')
		cube.info.direction = north;
	else if (c == 'S')
		cube.info.direction = south;
	else if (c == 'E')
		cube.info.direction = east;
	else if (c == 'W')
		cube.info.direction = west;
	return (cube);
}

t_cubed	parse_single_line(t_cubed cube, int line, char *str)
{
	int	x;

	x = 0;
	while (str && str[x])
	{
		is_in_set(str[x], " 01NSWE\n");
		if (str[x] == ' ')
			cube.map[line][x] = nonPlayable;
		else if (str[x] == '0')
			cube.map[line][x] = empty;
		else if (str[x] == '1')
			cube.map[line][x] = wall;
		else if (str[x] != '\n')
		{
			if (cube.info.player_x)
				one_string_error("Too many player characters found");
			cube.info.player_y = line;
			cube.info.player_x = x;
			cube.map[line][x] = north;
			cube = determine_player_direction(cube, str[x]);
		}
		x++;
	}
	return (cube);
}

t_cubed	parse_list_to_map(t_cubed cube, t_list_map *head)
{
	t_list_map	*search;

	search = head;
	while (search)
	{
		cube = parse_single_line(cube, search->line, search->str);
		search = search->next;
	}
	return (cube);
}
