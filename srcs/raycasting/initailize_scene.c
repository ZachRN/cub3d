/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initailize_scene.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 12:20:46 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/11/19 14:32:10 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"
#include "vector_math.h"

t_player	*init_player(t_map *map_info, int fov)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		exit(EXIT_FAILURE);
	player->base_dir.x = 0;
	player->base_dir.y = -1;
	player->pos.x = map_info->player_x + 0.5;
	player->pos.y = map_info->player_y + 0.5;
	player->fov = fov;
	player->phi = (startdir - 2) * ((90 * M_PI) / 180);
	base_cam.x = tan(player->phi * 0.5);
	base_cam.y = 0;
	player->dir = rotate_vector(player->phi, base_dir);
	player->cam = rotate_vector(player->phi, base_cam);
	// printf("phi: %lf\n", player->phi);
	// printf("player direction: %lf : %lf\n\n", player->dir.x, player->dir.y);
	// printf("Cam direction: %lf : %lf\n\n", player->cam.x, player->cam.y);
	// player->cam = add_vector(add_vector(player->pos, player->dir), player->cam);
	// printf("Cam edge location: %lf : %lf\n", player->cam.x, player->cam.y);
	// printf("player location:   %lf : %lf\n\n", player->pos.x, player->pos.y);
	return (player);
}

t_scene	*init_scene(t_map *map_info, char *win_name)
{
	t_scene		*scene;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		exit(EXIT_FAILURE);
	scene->window = mlx_init(WINWIDTH, WINHEIGHT, win_name, false);
	scene->player = init_player(map_info, 90);
	scene->wall_displ = mlx_new_image(scene->window, WINWIDTH, WINHEIGHT);
	return (scene);
}

void	free_scene(t_scene *scene)
{
	free(scene->player);
	free(scene);
}
