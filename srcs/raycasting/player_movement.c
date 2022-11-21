/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_movement.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 12:17:38 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/11/21 14:11:17 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "raycasting.h"
#include <math.h>

void	update_player_rot(double rotation, t_scene *scene)
{
	scene->player->phi += rotation;
	scene->player->dir = rotate_vector(scene->player->phi, \
										scene->player->base_dir);
	scene->player->cam = rotate_vector(scene->player->phi, \
										scene->player->base_cam);
	scene->player->has_moved = true;
}

void	player_walk(double distance, t_scene *scene)
{
	double	checkx;
	double	checky;

	checkx = scene->player->pos.x + 1.5 * distance * scene->player->dir.x;
	checky = scene->player->pos.y + 1.5 * distance * scene->player->dir.y;
	if (scene->map[(long int)scene->player->pos.y][(long int)checkx] <= 0)
		scene->player->pos.x += distance * scene->player->dir.x;
	if (scene->map[(long int)checky][(long int)scene->player->pos.x] <= 0)
		scene->player->pos.y += distance * scene->player->dir.y;
	scene->player->has_moved = true;
}

void	player_strafe(double distance, t_scene *scene)
{
	t_vector	strifedir;
	double		checkx;
	double		checky;

	strifedir = rotate_vector((M_PI / 2), scene->player->dir);
	checkx = scene->player->pos.x + 1.5 * distance * strifedir.x;
	checky = scene->player->pos.y + 1.5 * distance * strifedir.y;
	if (scene->map[(long int)scene->player->pos.y][(long int)checkx] <= 0)
		scene->player->pos.x += distance * strifedir.x;
	if (scene->map[(long int)checky][(long int)scene->player->pos.x] <= 0)
		scene->player->pos.y += distance * strifedir.y;
	scene->player->has_moved = true;
}
