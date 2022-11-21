/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 15:06:47 by znajda        #+#    #+#                 */
/*   Updated: 2022/11/21 14:22:18 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_errors.h"
#include "initialize_cube.h"
#include "parse.h"
#include "raycasting.h"
#include <stdlib.h>

void	free_stuff(t_cubed cubed)
{
	unsigned int	i;

	i = 0;
	while (i < cubed.info.max_rows + 2)
	{
		free(cubed.map[i]);
		i++;
	}
	free(cubed.map);
}

int	main(int argc, char *argv[])
{
	t_cubed	cube;

	if (argc != 2)
		one_string_error("Not correct amount of arguements");
	cube = initialize_cubed();
	cube = parse_file(cube, argv[1]);
	start_game_loop(&cube);
	free_stuff(cube);
	return (0);
}
