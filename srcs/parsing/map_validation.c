/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_validation.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 12:50:25 by znajda        #+#    #+#                 */
/*   Updated: 2022/11/19 13:12:15 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_errors.h"
#include "extension_check.h"

#include <stdio.h>

void	check_edge(t_cubed cubed)
{
	unsigned int	i;

	i = 0;
	while (i <= cubed.info.max_cols)
	{
		if (cubed.map[0][i] != nonPlayable && cubed.map[0][i] != wall)
			one_string_error(MAP_NOT_SURRONDED);
		if ((cubed.map[cubed.info.max_rows][i] != nonPlayable)
			&& (cubed.map[cubed.info.max_rows][i] != wall))
			one_string_error(MAP_NOT_SURRONDED);
		i++;
	}
	i = 0;
	while (i <= cubed.info.max_rows)
	{
		if (cubed.map[i][0] != nonPlayable && cubed.map[i][0] != wall)
			one_string_error(MAP_NOT_SURRONDED);
		if ((cubed.map[i][cubed.info.max_cols] != nonPlayable)
			&& (cubed.map[i][cubed.info.max_cols] != wall))
			one_string_error(MAP_NOT_SURRONDED);
		i++;
	}
}

void	check_around(t_cubed cube, unsigned int row, unsigned int col)
{
	if (cube.map[row - 1][col] == nonPlayable)
		one_string_error(MAP_NOT_SURRONDED);
	if (cube.map[row + 1][col] == nonPlayable)
		one_string_error(MAP_NOT_SURRONDED);
	if (cube.map[row][col - 1] == nonPlayable)
		one_string_error(MAP_NOT_SURRONDED);
	if (cube.map[row][col + 1] == nonPlayable)
		one_string_error(MAP_NOT_SURRONDED);
	if (cube.map[row - 1][col - 1] == nonPlayable)
		one_string_error(MAP_NOT_SURRONDED);
	if (cube.map[row - 1][col + 1] == nonPlayable)
		one_string_error(MAP_NOT_SURRONDED);
	if (cube.map[row + 1][col - 1] == nonPlayable)
		one_string_error(MAP_NOT_SURRONDED);
	if (cube.map[row + 1][col + 1] == nonPlayable)
		one_string_error(MAP_NOT_SURRONDED);
}

void	check_inside_cube(t_cubed cubed)
{
	unsigned int	row;
	unsigned int	col;

	row = 1;
	while (row < cubed.info.max_rows)
	{
		col = 1;
		while (col < cubed.info.max_cols)
		{
			if (cubed.map[row][col] != wall
				&& cubed.map[row][col] != nonPlayable)
				check_around(cubed, row, col);
			col++;
		}
		row++;
	}
}

void	check_texture_extension(t_cubed cubed)
{
	if (!extension_check(cubed.textures.north, ".png"))
		extension_error_print(WRONG_EXTENSION, "*.png", cubed.textures.north);
	if (!extension_check(cubed.textures.east, ".png"))
		extension_error_print(WRONG_EXTENSION, "*.png", cubed.textures.east);
	if (!extension_check(cubed.textures.south, ".png"))
		extension_error_print(WRONG_EXTENSION, "*.png", cubed.textures.south);
	if (!extension_check(cubed.textures.west, ".png"))
		extension_error_print(WRONG_EXTENSION, "*.png", cubed.textures.west);
}

void	map_validation(t_cubed cubed)
{
	if (cubed.info.max_cols < 2 || cubed.info.max_rows < 2)
		one_string_error("The map isn't large enough to be valid!");
	check_edge(cubed);
	check_inside_cube(cubed);
	check_texture_extension(cubed);
	if (!cubed.info.player_x)
		one_string_error("No player Character Found");
}
