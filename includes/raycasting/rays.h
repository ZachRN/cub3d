/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rays.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 14:06:15 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/11/19 16:21:05 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

# define EPSILON 0.00001

#include "vector_maths.h"
#include "scene.h"

typedef struct s_ray
{
	t_vector	dir;
	long int	mapx;
	long int	mapy;
	t_vector	*delta_dist;
	t_vector	*side_dist;
	double		wall_dist;
	int			stepx;
	int			stepy;
}	t_ray;

t_ray	*init_ray(t_scene *scene, double cam_x);
void	free_ray(t_ray *ray);

#endif