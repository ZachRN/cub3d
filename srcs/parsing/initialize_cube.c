/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_cube.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 13:31:37 by znajda        #+#    #+#                 */
/*   Updated: 2022/11/18 17:52:21 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <unistd.h>

static t_rgba	initialize_colors(void)
{
	t_rgba to_return;

	to_return.r = 0;
	to_return.g = 0;
	to_return.b = 0;
	to_return.a = 0;
	return (to_return);
}

static t_map initialize_info(void)
{
	t_map info;

	info.direction = 0;
	info.player_x = 0;
	info.player_y = 0;
	info.max_cols = 0;
	info.max_rows = 0;
	return (info);
}

static t_textures initialize_textures(void)
{
	t_textures textures;

	textures.north = NULL;
	textures.west = NULL;
	textures.south = NULL;
	textures.east = NULL;
	return (textures);
}

t_cubed	initialize_cubed(void)
{
	t_cubed cubed;

	cubed.floor = initialize_colors();
	cubed.ceiling = initialize_colors();
	cubed.textures = initialize_textures();
	cubed.info = initialize_info();
	cubed.map_file = NULL;
	cubed.map = NULL;
	return (cubed);
}
