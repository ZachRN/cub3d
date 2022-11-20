/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_hooks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 15:32:35 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/11/20 23:18:37 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "input_hooks.h"
#include "player_movement.h"
#include <math.h>
#include "raycasting.h"

void	hooks(void *data)
{
	t_scene	*scene;

	scene = (t_scene *)data;
	if (mlx_is_key_down(scene->window, MLX_KEY_LEFT))
		update_player_rot((-2.0 * M_PI / 180), scene);
	if (mlx_is_key_down(scene->window, MLX_KEY_RIGHT))
		update_player_rot((2.0 * M_PI / 180), scene);
	if (mlx_is_key_down(scene->window, MLX_KEY_W))
		player_walk(0.1, scene);
	if (mlx_is_key_down(scene->window, MLX_KEY_S))
		player_walk(-0.1, scene);
	if (mlx_is_key_down(scene->window, MLX_KEY_A))
		player_strafe(-0.1, scene);
	if (mlx_is_key_down(scene->window, MLX_KEY_D))
		player_strafe(0.1, scene);
	if (scene->player->has_moved == true)
		raycasting(scene);
	scene->player->has_moved = false;
}

void	keyhooks(mlx_key_data_t keydata, void *data)
{
	t_scene	*scene;

	scene = data;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(scene->window);
}
