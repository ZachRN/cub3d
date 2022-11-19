/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 12:58:00 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/11/19 17:18:24 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include "rays.h"
#include "draw_images.h"
#include "ft_memset.h"

void	print_ray()

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
	if (side == 0)
		ray->wall_dist = (ray->side_dist->x - ray->delta_dist->x);
	else
		ray->wall_dist = (ray->side_dist->y - ray->delta_dist->y);
}

t_column	*calculate_column(int window_height, t_ray *ray, u_int32_t *side)
{
	t_column	*column;
	long int	lineheight;

	column = malloc(sizeof(t_column));
	if (!column)
		exit(EXIT_FAILURE);
	lineheight = (long int)(((double)window_height) / ray->wall_dist);
	column->top = (-lineheight / 2) + (window_height / 2);
	if (column->top < 0)
		column->top = 0;
	column->bottom = (lineheight / 2) + (window_height / 2);
	if (column->bottom > window_height)
		column->bottom = window_height - 1;
	if (*side == 1 && ray->dir.y > 0)
		column->colour = 0xFF0000FF;
	else if (*side == 1 && ray->dir.y < 0)
		column->colour = 0x00FF00FF;
	else if (*side == 0 && ray->dir.x > 0)
		column->colour = 0x0000FFFF;
	else
		column->colour = 0xFFFF00FF;
	return (column);
}

void	raycasting(t_scene *scene)
{
	t_ray		*ray;
	t_column	*column;
	u_int32_t	pxl_x;
	u_int32_t	side;
	double		cam_x;

	ft_memset(scene->wall_displ->pixels, 0, scene->wall_displ->width \
			* scene->wall_displ->height * sizeof(int32_t));
	pxl_x = 0;
	side = 0;
	while (pxl_x < scene->wall_displ->width)
	{
		cam_x = (2.0 * (double)pxl_x) / (double)scene->wall_displ->width - 1.0;
		cam_x += (1.0 / (2.0 * (double)scene->wall_displ->width));
		printf("camx: %lf\n", cam_x);
		ray = init_ray(scene, cam_x);
		find_wall_distance(scene->map, ray, &side);
		column = calculate_column(scene->window->height, ray, &side);
		draw_column(pxl_x, column, scene);
		free(column);
		pxl_x++;
	}
}
