/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_errors.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 15:22:09 by znajda        #+#    #+#                 */
/*   Updated: 2022/11/16 16:12:56 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ERRORS_H
# define CUB3D_ERRORS_H

# define WRONG_EXTENSION "The extension did not match the required typing"
# define OPEN_FAILUE "Couldn't open this file: "
# define MALLOC_ERROR "A malloc failed in: "
# define FILE_ERROR "Passed an invalid file descriptor in: "
# define MAP_EARLY_END "The map ended before all information was given"
# define UNEXPECTED_TOKEN "Unexpected Indetifier found on line: "
# define NORTH_EXISTS "North Texture Already Exists"
# define SOUTH_EXISTS "South Texture Already Exists"
# define EAST_EXISTS "East Texture Already Exists"
# define WEST_EXISTS "West Texture Already Exists"
# define FLOOR_EXISTS "Floor Colors Already Exists"
# define CEILING_EXISTS "Ceiling Colors Already Exists"
# define TOO_MANY_COMMAS "Too many commas were found"
# define TOO_LITTLE_COMMAS "Too little commas were found"
# define NON_NUMBER_INPUT "Floor or Ceiling received a non numerical input"
# define NUMBER_TOO_HIGH "Floor or Ceiling received a larger then 255 input"

void	extension_error_print(char *error, char *expected, char *input);
void	two_strings_error(char *str, char *str2);
void	one_string_error(char *str);

#endif
