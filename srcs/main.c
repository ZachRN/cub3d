/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 15:06:47 by znajda        #+#    #+#                 */
/*   Updated: 2022/11/19 18:23:15 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "initialize_cube.h"
#include "parse.h"
#include "raycasting.h"
/*Headers here for testing but may (possibly) be removed later*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	checkleaks()
{
	system("leaks -q cub3d > report.log");
	system("lsof -c cub3d >> report.log");
}

void	test_print_cubed(t_cubed *cube)
{
	printf("Map File:%s\n", cube->map_file);
	printf("North Texture:%s\nEast Texture:%s\n", cube->textures.north, cube->textures.east);
	printf("South Textures:%s\nWest Textures:%s\n", cube->textures.south, cube->textures.west);
	printf("Ceiling R:[%d] G:[%d] B:[%d] a:[%d] Value: [%u]\n", cube->ceiling.r, cube->ceiling.g, cube->ceiling.b, cube->ceiling.a, cube->ceiling.rgba);
	printf("Floor R:[%d] G:[%d] B:[%d] a:[%d] Value: [%u]\n", cube->floor.r, cube->floor.g, cube->floor.b, cube->floor.a, cube->floor.rgba);
	printf("Player Direction: %d\nMax cols: [%d] Max rows: [%d]\n", cube->info.direction, cube->info.max_cols, cube->info.max_rows);
	printf("Player X:[%d] Player Y:[%d]\n", cube->info.player_x, cube->info.player_y);
}

int main(int argc, char *argv[])
{
	t_cubed cube;

	// atexit(checkleaks);
	if (argc != 2)
		return (0);
	cube = initialize_cubed();
	cube = parse_file(cube, argv[1]);
	test_print_cubed(&cube);
	start_game_loop(&cube);
	exit(EXIT_SUCCESS);
}
