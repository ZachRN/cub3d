/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 15:06:47 by znajda        #+#    #+#                 */
/*   Updated: 2022/11/16 16:26:08 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "initialize_cube.h"
#include "parse.h"
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
	printf("Player Direction: %d\nMax X: [%d] Max Y: [%d]\n", cube->info.direction, cube->info.max_x, cube->info.max_y);
}

int main(int argc, char *argv[])
{
	t_cubed cube;

	atexit(checkleaks);
	if (argc != 2)
		return (0);
	cube = initialize_cubed();
	// cube.floor.rgba = 0xFF00FFFF;
	cube = parse_file(cube, argv[1]); 
	test_print_cubed(&cube);
	//in a non empty repo
	(void)argv; // Just getting rid of -werror atm with this
	exit(EXIT_SUCCESS);
}