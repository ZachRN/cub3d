/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_images.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 12:52:40 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/11/19 16:07:10 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_IMAGES_H
# define DRAW_IMAGES_H

#include "MLX42.h"
#include "scene.h"
#include "cub3d.h"

typedef struct s_column
{
	int			top;
	int			bottom;
	uint32_t	colour;
}	t_column;

void		set_colour_to_pixel(u_int32_t rgba, uint8_t *pixel);
mlx_image_t	*set_background(t_scene *scene, t_cubed *cubed);
void		draw_column(int x, t_column *column, t_scene *scene);

#endif