/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_ray.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 14:07:11 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/11/19 18:56:25 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"
#include <math.h>
#include <stdlib.h>

#include <stdio.h>

static t_vector	*init_ray_delta_dist(t_vector raydir)
{
	t_vector	*delta_dist;

	delta_dist = malloc(sizeof(t_vector));
	if (!delta_dist)
		exit(EXIT_FAILURE);
	if (raydir.x < EPSILON && raydir.x > -1.0 * EPSILON)
		delta_dist->x = pow(10, 30);
	else
		delta_dist->x = fabs(1 / raydir.x);
	if (raydir.y < EPSILON && raydir.y > -1.0 * EPSILON)
		delta_dist->y = pow(10, 30);
	else
		delta_dist->y = fabs(1 / raydir.y);
	return (delta_dist);
}

static t_vector	*init_ray_side_dist(t_scene *scene, t_ray *ray)
{
	t_vector	*sidedist;

	sidedist = malloc(sizeof(t_vector));
	if (!sidedist)
		exit(EXIT_FAILURE);
	ray->stepx = 1;
	ray->stepy = 1;
	if (ray->dir.x < 0)
	{
		ray->stepx *= -1;
		sidedist->x = (scene->player->pos.x - (double)ray->mapx) \
						* ray->delta_dist->x;
	}
	else
		sidedist->x = ((double)ray->mapx + 1.0 - scene->player->pos.x) \
						* ray->delta_dist->x;
	if (ray->dir.y < 0)
	{
		ray->stepy = -1;
		sidedist->y = (scene->player->pos.y - ray->mapy) * ray->delta_dist->y;
	}
	else
		sidedist->y = ((double)ray->mapy + 1 - scene->player->pos.y) \
						* ray->delta_dist->y;
	return (sidedist);
}

t_ray	*init_ray(t_scene *scene, double cam_x)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		exit(EXIT_FAILURE);
	ray->dir.x = scene->player->dir.x + scene->player->cam.x * cam_x;
	ray->dir.y = scene->player->dir.y + scene->player->cam.y * cam_x;
	ray->mapx = (long int)scene->player->pos.x;
	ray->mapy = (long int)scene->player->pos.y;
	ray->delta_dist = init_ray_delta_dist(ray->dir);
	ray->side_dist = init_ray_side_dist(scene, ray);
	ray->wall_dist = 0;
	return (ray);
}

void	free_ray(t_ray *ray)
{
	free(ray->delta_dist);
	free(ray->side_dist);
	free(ray);
}
