/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 12:22:03 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/11/19 14:32:49 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "vector_maths.h"
# include "../mlx42/include/MLX42/MLX42.h"

typedef struct s_player
{
	t_vector	pos;
	t_vector	base_dir;
	t_vector	base_cam;
	t_vector	dir;
	u_int32_t	fov;
	t_vector	cam;
	double		phi;
}	t_player;

typedef struct s_scene
{
	mlx_t		*window;
	t_player	*player;
	mlx_image_t	*wall_displ;
}	t_scene;

t_scene		*init_scene(t_map *map_info, char *win_name);
t_player	*init_player(int posx, int posy, int fov, int startdir);

#endif
