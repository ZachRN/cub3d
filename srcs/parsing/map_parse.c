/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parse.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/18 12:26:52 by znajda        #+#    #+#                 */
/*   Updated: 2022/11/18 19:51:36 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_errors.h"
#include "cube_list.h"
#include "list_to_map.h"
#include "utils.h"

#include <stdio.h>

t_cubed		malloc_cubed_map(t_cubed cube, t_list_map *head)
{
	t_list_map *search;
	unsigned int i;

	i = 0;
	search = head;
	while (search->next)
	{
		if ((unsigned int)ft_strlen(search->str) > cube.info.max_cols)
			cube.info.max_cols = (unsigned int)ft_strlen(search->str);
		search = search->next;
	}
	cube.info.max_rows = search->line;
	cube.map = (int **)malloc(cube.info.max_rows * sizeof(int *));
	// printf("line[%d] str[%d]\n", cube.info.max_rows, cube.info.max_cols);
	if (!cube.map)
		two_strings_error(MALLOC_ERROR, "map_parse.c; line");
	while (i <= cube.info.max_rows)
	{
		cube.map[i] = (int *)malloc(cube.info.max_cols * sizeof(int));
		if (!cube.map[i])
			two_strings_error(MALLOC_ERROR, "map_parse.c; line");
		i++;
	}
	// for (unsigned int x = 0; x <= cube.info.max_rows; x++)
    // {
	// 	 for (unsigned int y = 0; y <= cube.info.max_cols; y++)
	// 	{
	// 		write(1, "x", 1);
	// 	}
	// 	write(1, "\n", 1);
	// }
	return (cube);
}

t_cubed init_map(t_cubed cubed)
{
	unsigned int cols;
	unsigned int rows;


	// printf("max_rows[%d] max_cols[%d]\n", cubed.info.max_rows, cubed.info.max_cols);
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
	// printf("max_rows[%d] max_cols[%d]\n", cubed.info.max_rows, cubed.info.max_cols);
	return (cubed);
}

void	validate_map(t_cubed cubed)
{
	unsigned int rows;
	unsigned int cols;

	rows = 0;
	while (rows <= cubed.info.max_rows)
	{
		cols = 0;
		while (cols <= cubed.info.max_cols)
		{
			if (cubed.map[rows][cols] == nonPlayable)
				write(1, "x", 1);
			else if (cubed.map[rows][cols] == wall)
				write(1, "1", 1);
			else if (cubed.map[rows][cols] == empty)
				write(1, "0", 1);
			else if (cubed.map[rows][cols] == north)
				write(1, "N", 1);
			else if (cubed.map[rows][cols] == east)
				write(1, "E", 1);
			else if (cubed.map[rows][cols] == south)
				write(1, "S", 1);
			else if (cubed.map[rows][cols] == west)
				write(1, "W", 1);
			cols++;
		}
		rows++;
		write(1, "\n", 1);
	}
}

t_list_map	*delete_list(t_list_map *head)
{
	if (!head)
		return (NULL);
	while (head)
		head = delete_one_element(head);
	return (NULL);
}

void display_list(t_list_map *head)
{
	t_list_map *search;

	search = head;
	while (search)
	{
	printf("line[%d] str[%s]\n", search->line, search->str);
	search = search->next;
	}
}

t_cubed parse_map(t_cubed cubed, int map_fd)
{
	t_list_map *head;

	head = read_map_list(map_fd);
	cubed = malloc_cubed_map(cubed, head);
	cubed = init_map(cubed);
	// validate_map(cubed);
	// display_list(head);
	cubed = parse_list_to_map(cubed, head);
	// printf("4.0\n");
	head = delete_list(head);
	// printf("5.0\n");
	validate_map(cubed);
	return (cubed);
}