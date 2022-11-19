/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_images.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 12:50:01 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/11/19 17:16:36 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "draw_images.h"
#include "cub3d.h"

void	set_colour_to_pixel(u_int32_t rgba, uint8_t *pixel)
{
	pixel[0] = ((rgba >> 24) & 0xFF);
	pixel[1] = ((rgba >> 16) & 0xFF);
	pixel[2] = ((rgba >> 8) & 0xFF);
	pixel[3] = (rgba & 0xFF);
}

mlx_image_t	*set_background(t_scene *scene, t_cubed *cubed)
{
	mlx_image_t	*background;
	u_int32_t	idx;

	background = mlx_new_image(scene->window, scene->window->width, \
								scene->window->height);
	idx = 0;
	while (idx < (background->width * background->height / 2))
	{
		set_colour_to_pixel(cubed->ceiling.rgba, \
							&background->pixels[(4 * idx)]);
		idx++;
	}
	while (idx < (background->width * background->height))
	{
		set_colour_to_pixel(cubed->floor.rgba, &background->pixels[(4 * idx)]);
		idx++;
	}
	mlx_image_to_window(scene->window, background, 0, 0);
	return (background);
}

void	draw_column(int x, t_column *column, t_scene *scene)
{
	int	idx;

	idx = (column->top * scene->window->width) + x;
	while (idx < (column->bottom * scene->window->width))
	{
		set_colour_to_pixel(column->colour, \
				&scene->wall_displ->pixels[4 * idx]);
		idx += scene->window->width;
	}
}
