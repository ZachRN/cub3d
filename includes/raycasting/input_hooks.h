/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_hooks.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 15:34:21 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/11/19 15:35:34 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HOOKS_H
# define INPUT_HOOKS_H

# include "MLX42.h"

void	hooks(void *data);
void	keyhooks(mlx_key_data_t keydata, void *data);

#endif