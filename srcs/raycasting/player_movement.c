/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_movement.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 12:17:38 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/11/19 18:32:34 by mteerlin      ########   odam.nl         */
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
	raycasting(scene);
}

void	player_walk(double distance, t_scene *scene)
{
	double	newx;
	double	newy;

	newx = scene->player->pos.x + distance * scene->player->dir.x;
	newy = scene->player->pos.y + distance * scene->player->dir.y;
	if (scene->map[(long int)scene->player->pos.y][(long int)newx] <= 0)
		scene->player->pos.x = newx;
	if (scene->map[(long int)newy][(long int)scene->player->pos.x] <= 0)
		scene->player->pos.y = newy;
	raycasting(scene);
}

void	player_strafe(double distance, t_scene *scene)
{
	t_vector	strifedir;
	double		newx;
	double		newy;

	strifedir = rotate_vector((M_PI / 2), scene->player->dir);
	newx = scene->player->pos.x + distance * strifedir.x;
	newy = scene->player->pos.y + distance * strifedir.y;
	if (scene->map[(long int)scene->player->pos.y][(long int)newx] <= 0)
		scene->player->pos.x = newx;
	if (scene->map[(long int)newy][(long int)scene->player->pos.x] <= 0)
		scene->player->pos.y = newy;
	raycasting(scene);
}
