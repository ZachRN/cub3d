/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture_parse.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 14:29:35 by znajda        #+#    #+#                 */
/*   Updated: 2022/11/16 17:23:34 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "initialize_structs.h"
#include "utils.h"
#include "cub3d_errors.h"
#include "cub3d.h"

#include <stdio.h>

char	*texture_parse(char *str)
{
	int	start;
	int	end;

	start = 2;
	while (str[start] && str[start] == ' ')
		start++;
	end = ft_strlen(str) - 1;
	while (end != start && str[end] == ' ')
		end--;
	if (end == start)
		one_string_error("No path supplied");
	return (ft_substr(str, start, end - start));
}

void	check_commas(char *str)
{
	int i;
	int comma;

	comma = 0;
	i = 0;
	while (str[i])
	{
		i++;
		if (str[i] == ',')
			comma++;
	}
	if (comma > 2)
		one_string_error(TOO_MANY_COMMAS);
	else if (comma < 2)
		one_string_error(TOO_LITTLE_COMMAS);
}

unsigned int	cubed_atoi(char *str)
{
	unsigned int i;
	unsigned int num;

	i = 0;
	num = 0;
	if (!str || !str[0])
		one_string_error("No number supplied to cubed_atoi");
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			one_string_error(NON_NUMBER_INPUT);
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if (num > 255)
		one_string_error(NUMBER_TOO_HIGH);
	return (num);
}

t_rgba color_parse(char *str)
{
	t_rgba to_return;
	char **split_to;
	char *to_trim;
	int start;

	start = 1;
	check_commas(str);
	while (str[start] && str[start] == ' ')
		start++;
	split_to = ft_split(str + start, ',');
	to_trim = ft_strtrim(split_to[0], " ,\n");
	to_return.r = cubed_atoi(to_trim);
	free(to_trim);
	to_trim = ft_strtrim(split_to[1], " ,\n");
	to_return.g = cubed_atoi(to_trim);
	free(to_trim);
	to_trim = ft_strtrim(split_to[2], " ,\n");
	to_return.b = cubed_atoi(to_trim);
	free(to_trim);
	free_my_lines(split_to);
	to_return.a = 255; // maybe change, ask michiel
	return (to_return);
}
