/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_movement.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 16:22:51 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/11/19 18:31:41 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_MOVEMENT_H
# define PLAYER_MOVEMENT_H
# include "scene.h"

void	update_player_rot(double rotation, t_scene *scene);
void	player_walk(double distance, t_scene *scene);
void	player_strafe(double distance, t_scene *scene);

#endif