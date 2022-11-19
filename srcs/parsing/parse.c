/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 15:18:08 by znajda        #+#    #+#                 */
/*   Updated: 2022/11/18 14:23:48 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_errors.h"
#include "utils.h"
#include "parse_nonmap_line.h"
#include "extension_check.h"
#include "map_parse.h"
#include <fcntl.h>
#include <unistd.h>

t_cubed parse_file(t_cubed cube, char *map_file)
{
	int	map_fd;
	cube.map_file = extension_check(map_file, ".cub");
	if (!cube.map_file)
		extension_error_print(WRONG_EXTENSION, "*.cub", map_file);
	map_fd = open(cube.map_file, O_RDONLY);
	if (map_fd < 0)
		two_strings_error(OPEN_FAILUE, cube.map_file);
	cube = non_map_parse(cube, map_fd);
	cube = parse_map(cube, map_fd);
	close(map_fd);
	return (cube);
}
