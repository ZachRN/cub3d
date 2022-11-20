/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_images.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 12:52:40 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/11/20 21:36:32 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_IMAGES_H
# define DRAW_IMAGES_H

#include "MLX42.h"
#include "scene.h"
#include "cub3d.h"

typedef struct s_column
{
	long int		lineheight;
	int				top;
	int				bottom;
	int				start;
	int				end;
	uint32_t		colour;
	mlx_texture_t	*texture;
	int				texture_x;
}	t_column;

mlx_image_t	*set_background(t_scene *scene, t_cubed *cubed);
void		draw_column(int x, t_column *column, t_scene *scene);

#endif