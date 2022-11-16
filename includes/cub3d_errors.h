/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_errors.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 15:22:09 by znajda        #+#    #+#                 */
/*   Updated: 2022/11/15 17:02:11 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ERRORS_H
# define CUB3D_ERRORS_H

# define WRONG_EXTENSION "The extension did not match the required typing"
# define OPEN_FAILUE "Couldn't open this file: "

void	extension_error_print(char *error, char *expected, char *input);
void	two_strings_error(char *str, char *str2);

#endif
