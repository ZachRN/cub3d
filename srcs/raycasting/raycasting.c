/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 12:58:00 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/11/21 14:11:22 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include "rays.h"
#include "draw_images.h"
#include "ft_memset.h"
#include "vector_maths.h"
#include <math.h>

void	find_wall_distance(int **map, t_ray *ray, u_int32_t *side)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist->x < ray->side_dist->y)
		{
			ray->side_dist->x += ray->delta_dist->x;
			ray->mapx += ray->stepx;
			*side = 0;
		}
		else
		{
			ray->side_dist->y += ray->delta_dist->y;
			ray->mapy += ray->stepy;
			*side = 1;
		}
		if (map[ray->mapy][ray->mapx] == wall)
			hit = wall;
	}
	if (*side == 0)
		ray->wall_dist = (ray->side_dist->x - ray->delta_dist->x);
	else
		ray->wall_dist = (ray->side_dist->y - ray->delta_dist->y);
}

static void	get_texture_column(t_column *column, t_scene *scene, \
								t_ray *ray, u_int32_t *side)
{
	double	x_wall;

	if (*side == 1 && ray->dir.y > 0)
		column->texture = scene->south;
	else if (*side == 1 && ray->dir.y < 0)
		column->texture = scene->north;
	else if (*side == 0 && ray->dir.x > 0)
		column->texture = scene->east;
	else
		column->texture = scene->west;
	if (*side == 0)
		x_wall = scene->player->pos.y + (ray->wall_dist * ray->dir.y);
	else
		x_wall = scene->player->pos.x + (ray->wall_dist * ray->dir.x);
	x_wall -= (long int)x_wall;
	column->texture_x = (int)(x_wall * (double)column->texture->width);
	if ((*side == 1 && ray->dir.y < 0) || (*side == 0 && ray->dir.x > 0))
		column->texture_x = column->texture->width - column->texture_x - 1;
}

t_column	*calculate_column(t_scene *scene, t_ray *ray, u_int32_t *side)
{
	t_column	*column;

	column = malloc(sizeof(t_column));
	if (!column)
		exit(EXIT_FAILURE);
	if (ray->wall_dist < EPSILON && ray->wall_dist > -EPSILON)
		column->lineheight = pow(10, 30);
	else
		column->lineheight = (long int)(scene->window->height / ray->wall_dist);
	column->top = (-(column->lineheight) / 2) + (scene->window->height / 2);
	column->start = column->top;
	if (column->start < 0)
		column->start = 0;
	column->bottom = (column->lineheight / 2) + (scene->window->height / 2);
	column->end = column->bottom;
	if (column->end > scene->window->height)
		column->end = scene->window->height;
	get_texture_column(column, scene, ray, side);
	return (column);
}

void	raycasting(t_scene *scene)
{
	t_ray		*ray;
	t_column	*column;
	u_int32_t	pxl_x;
	u_int32_t	side;
	double		cam_x;

	ft_memset(scene->walls->pixels, 0, scene->walls->width \
			* scene->walls->height * sizeof(u_int32_t));
	pxl_x = 0;
	side = 0;
	while (pxl_x < scene->walls->width)
	{
		cam_x = (2.0 * (double)pxl_x) / (double)scene->walls->width - 1.0;
		cam_x += (1.0 / (2.0 * (double)scene->walls->width));
		ray = init_ray(scene, cam_x);
		find_wall_distance(scene->map, ray, &side);
		column = calculate_column(scene, ray, &side);
		free_ray(ray);
		draw_column(pxl_x, column, scene);
		free(column);
		pxl_x++;
	}
}
