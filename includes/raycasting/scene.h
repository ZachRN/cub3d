/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 12:22:03 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/11/20 23:15:26 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "vector_maths.h"
# include "MLX42.h"
# include "cub3d.h"
# include <stdbool.h>

typedef struct s_player
{
	t_vector	pos;
	t_vector	base_dir;
	t_vector	base_cam;
	t_vector	dir;
	u_int32_t	fov;
	t_vector	cam;
	double		phi;
	bool		has_moved;
}	t_player;

typedef struct s_scene
{
	mlx_t			*window;
	t_player		*player;
	mlx_image_t		*walls;
	mlx_texture_t	*north;
	mlx_texture_t	*east;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	int				**map;
}	t_scene;

t_scene	*init_scene(t_cubed *cubed, char *win_name);
void	free_scene(t_scene *scene);

#endif
