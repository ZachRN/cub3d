/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 13:48:24 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/11/21 14:12:21 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "scene.h"
# include "cub3d.h"

void	start_game_loop(t_cubed *cubed);
void	raycasting(t_scene *scene);

#endif