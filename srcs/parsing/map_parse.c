/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parse.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/18 12:26:52 by znajda        #+#    #+#                 */
/*   Updated: 2022/11/19 16:38:34 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_errors.h"
#include "cube_list.h"
#include "list_to_map.h"
#include "utils.h"
#include "map_validation.h"

#include <stdio.h>

t_cubed	malloc_cubed_map(t_cubed cube, t_list_map *head)
{
	t_list_map		*search;
	unsigned int	i;

	i = 0;
	search = head;
	while (search->next)
	{
		if ((unsigned int)ft_strlen(search->str) > cube.info.max_cols)
			cube.info.max_cols = (unsigned int)ft_strlen(search->str) - 1;
		search = search->next;
	}
	cube.info.max_rows = search->line + 1;
	cube.map = (int **)malloc((cube.info.max_rows + 1) * sizeof(int *));
	if (!cube.map)
		two_strings_error(MALLOC_ERROR, "map_parse.c; line");
	while (i <= cube.info.max_rows)
	{
		cube.map[i] = (int *)malloc(cube.info.max_cols * sizeof(int));
		if (!cube.map[i])
			two_strings_error(MALLOC_ERROR, "map_parse.c; line");
		i++;
	}
	cube.info.max_rows--;
	cube.info.max_cols--;
	return (cube);
}

t_cubed	init_map(t_cubed cubed)
{
	unsigned int	cols;
	unsigned int	rows;

	rows = 0;
	while (rows <= cubed.info.max_rows)
	{
		cols = 0;
		while (cols <= cubed.info.max_cols)
		{
			cubed.map[rows][cols] = nonPlayable;
			cols++;
		}
		rows++;
	}
	return (cubed);
}

void	delete_list(t_list_map *head)
{
	t_list_map	*search;

	search = head;
	while (head)
	{
		search = head;
		head = head->next;
		free(search->str);
		free(search);
	}
}

t_cubed	parse_map(t_cubed cubed, int map_fd)
{
	t_list_map	*head;

	head = read_map_list(map_fd);
	close(map_fd);
	cubed = malloc_cubed_map(cubed, head);
	cubed = init_map(cubed);
	cubed = parse_list_to_map(cubed, head);
	delete_list(head);
	map_validation(cubed);
	return (cubed);
}
