/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_images.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 12:52:40 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/11/19 12:54:42 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_IMAGES_H
# define DRAW_IMAGES_H

#include "MLX42.h"
#include "scene.h"

void		set_colour_to_pixel(u_int32_t rgba, uint8_t *pixel);
mlx_image_t	*set_background(t_scene *scene);
void		draw_column(int	x, int start, int end, uint32_t colour, mlx_image_t *wall_displ);

#endif