/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 12:58:00 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/11/19 15:11:15 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include "rays.h"
#include "draw_images.h"

typedef struct s_cullumn
{
	int			top;
	int			bottom;
	uint32_t	colour;
}	t_collumn;

void	find_wall_distance(int **map, t_ray *ray, int *side)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->mapx += ray->stepx;
			*side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->mapy += ray->stepy;
			*side = 1;
		}
		if (map[ray->mapy][ray->mapx] == wall)
			hit = wall;
	}
	if (side == 0)
		ray->walldist = (sidedist.x - deltadist.x);
	else
		ray->walldist = (sidedist.y - deltadist.y);
}

t_collumn	*calculate_collumn(int window_height, t_ray *ray, int *side)
{
	t_collumn	collumn;
	long int	lineheight;

	if (!collumn)
		exit(EXIT_FAILURE);
	lineheight = (long int)(((double)window_height) / ray->walldist);
	// printf("windown: %d,%d\n", WINWIDTH, WINHEIGHT);
	collumn->top = (-lineheight / 2) + (window_height / 2);
	if (collumn->top < 0)
		collumn->top = 0;
	collumn->bottom = (lineheight / 2) + (window_height / 2);
	if (collumn->bottom > window_height)
		collumn->bottom = window_height - 1;
	/*Setting wall colours*/
	if (*side == 1 && ray->dir.y > 0)
		colour = 0xFF0000FF;
	else if (*side == 1 && ray->dir.y < 0)
		colour = 0x00FF00FF;
	else if (*side == 0 && ray->dir.x > 0)
		colour = 0x0000FFFF;
	else
		colour = 0xFFFF00FF;
	return (collumn);
}

void	raycasting(t_scene *scene, int **map)
{
	t_ray		*ray;
	t_collumn	*collumn;
	int			pxl_x;
	int			side;
	double		cam_x;

	memset(scene->wall_display->pixels, 0, scene->wall_displ->width \
			* scene->wall_displ->height * sizeof(int32_t));
	pxl_x = 0;
	side = 0;
	while (psl_x < scene->wall_displ->width)
	{
		cam_x = (2.0 * (double)pxl_x) / (double)scene->wall_displ->width - 1.0;
		cam_x += (1.0 / (2.0 * (double)scene->wall_displ->width));
		ray = init_ray(scene, cam_x);
		find_wall_distance(map, ray, &side);
		collumn = calculate_collumn(scene->window->height, ray, &side);
		draw_column(pxl_x, drawstart, drawend, colour, scene);
		pxl_x++;
	}
}
