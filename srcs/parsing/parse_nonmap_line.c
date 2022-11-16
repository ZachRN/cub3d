/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_nonmap_line.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 14:13:24 by znajda        #+#    #+#                 */
/*   Updated: 2022/11/16 17:10:36 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "cub3d.h"
#include "cub3d_errors.h"
#include "initialize_structs.h"
#include "texture_parse.h"

#include <stdio.h>

static t_cubed determine_function(t_cubed cube, char *str)
{
	if (ft_strncmp(str, "NO", 2) == 0)
		cube.textures.north = texture_parse(str);
	else if (ft_strncmp(str, "SO", 2) == 0)
		cube.textures.south = texture_parse(str);
	else if (ft_strncmp(str, "EA", 2) == 0)
		cube.textures.east = texture_parse(str);
	else if (ft_strncmp(str, "WE", 2) == 0)
		cube.textures.west = texture_parse(str);
	else if (ft_strncmp(str, "F", 1) == 0)
		cube.floor = color_parse(str);
	else if (ft_strncmp(str, "C", 1) == 0)
		cube.ceiling = color_parse(str);
	else if (ft_strncmp(str, "\n", 2))
		one_string_error(UNEXPECTED_TOKEN);
	return (cube);
}

static void	duplicate_check(t_checklist *checklist, char c)
{
	if (checklist->NO && c == 'N')
		one_string_error(NORTH_EXISTS);
	else if (c == 'N')
		checklist->NO = 1;
	if (checklist->SO && c == 'S')
		one_string_error(SOUTH_EXISTS);
	else if (c == 'S')
		checklist->SO = 1;
	if (checklist->EA && c == 'E')
		one_string_error(EAST_EXISTS);
	else if (c == 'E')
		checklist->EA = 1;
	if (checklist->WE && c == 'W')
		one_string_error(WEST_EXISTS);
	else if (c == 'W')
		checklist->WE = 1;
	if (checklist->F && c == 'F')
		one_string_error(FLOOR_EXISTS);
	else if (c == 'F')
		checklist->F = 1;
	if (checklist->C && c == 'C')
		one_string_error(CEILING_EXISTS);
	else if (c == 'C')
		checklist->C = 1;
}

static t_cubed parse_line(t_cubed cube, char *str, t_checklist *checklist,
			t_readline *readline)
{
	static char	charset[7] = "\nNSWEFC";
	int		i;

	i = 0;
	readline->line++;
	while (charset[i])
	{
		if (str[0] == charset[i])
			break;
		i++;
	}
	if (!charset[i])
		one_string_error(UNEXPECTED_TOKEN); // MAYBE CHANGE LATER TO PRINT OUT LINE NUMBER
	duplicate_check(checklist, charset[i]);
	cube = determine_function(cube, str);
	return (cube);
}

static int	checklist_notover(t_checklist checklist)
{
	if (!checklist.NO)
		return (1);
	if (!checklist.SO)
		return (1);
	if (!checklist.WE)
		return (1);
	if (!checklist.EA)
		return (1);
	if (!checklist.F)
		return (1);
	if (!checklist.C)
		return (1);
	return (0);
}

t_cubed	non_map_parse(t_cubed cube, int map_fd)
{
	t_checklist checklist;
	t_readline	readline;
	char	*str;

	init_checklist(&checklist);
	init_readline(&readline);
	while (checklist_notover(checklist))
	{
		str = get_next_line(map_fd);
		if (!str)
			one_string_error(MAP_EARLY_END);
		cube = parse_line(cube, str, &checklist, &readline);
		free(str);	
	}
	str = get_next_line(map_fd);
	if (str && (str[0] != '0' || str[0] != '1' || str[0] != '2'))
		one_string_error("Parse Error");
	return (cube);
}
