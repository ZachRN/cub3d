/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window_loop.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 15:17:55 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/11/19 15:37:50 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "scene.h"
#include "draw_images.h"
#include "input_hooks.h"

void	cub3d(t_cubed *cubed)
{
	t_scene		scene;
	mlx_image_t	*background;

	scene = init_scene(cubed->info, "Cub3d");
	background = set_background(scene, cubed);
	raycasting(scene, cubed->map);
	mlx_image_to_window(scene->window, scene->wall_disp, 0, 0);
	mlx_loop_hook(scene->window, &hooks, scene);
	mlx_key_hook(scene->window, &keyhooks, scene);
	mlx_loop(scene->window);
	mlx_terminate(scene->window);
}
