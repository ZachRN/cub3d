/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_movement.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 12:17:38 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/11/19 15:13:09 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_math.h"
#include "raycasting.h"

void	update_player_rot(double rotation, t_player *player)
{
	t_vector	base_dir;
	t_vector	base_cam;

	base_dir.x = 0.0;
	base_dir.y = -1.0;
	base_cam.x = player->fov / 100.0;
	base_cam.y = 0;
	player->phi += rotation;
	player->dir = rotate_vector(player->phi, base_dir);
	player->cam = rotate_vector(player->phi, base_cam);
}

void	player_walk(double distance, t_player *player)
{
	double	newx;
	double	newy;

	newx = player->pos.x + distance * player->dir.x;
	newy = player->pos.y + distance * player->dir.y;
	if (worldMap[(long int)player->pos.y][(long int)newx] <= 0)
		player->pos.x = newx;
	if (worldMap[(long int)newy][(long int)player->pos.x] <= 0)
		player->pos.y = newy;
}

void	player_strafe(double distance, t_player *player)
{
	t_vector	strifedir;
	double		newx;
	double		newy;

	strifedir = rotate_vector((M_PI / 2), player->dir);
	newx = player->pos.x + distance * strifedir.x;
	newy = player->pos.y + distance * strifedir.y;
	if (worldMap[(long int)player->pos.y][(long int)newx] <= 0)
		player->pos.x = newx;
	if (worldMap[(long int)newy][(long int)player->pos.x] <= 0)
		player->pos.y = newy;
}
