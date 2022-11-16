/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_errors.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 15:21:43 by znajda        #+#    #+#                 */
/*   Updated: 2022/11/15 17:15:42 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>
#include <unistd.h>

void	extension_error_print(char *error, char *expected, char *input)
{
	write(2, "Error\n", ft_strlen("Error\n"));
	if (!error || !expected || !input)
		write(2, "Passed NULL to three_print_error\n",
			ft_strlen("Passed NULL to three_print_error\n"));
	write(2, error, ft_strlen(error));
	write(2, "\nExpected:[", ft_strlen("\nExpected:["));
	write(2, expected, ft_strlen(expected));
	write(2, "]\nReceived:[", ft_strlen("\n]Received:["));
	write(2, input, ft_strlen(input));
	write(2,"]\n",ft_strlen("]\n"));
	exit(EXIT_SUCCESS);
}

void	two_strings_error(char *str, char *str2)
{
	write(2, "Error\n", ft_strlen("Error\n"));
	if (!str || !str2)
		write(2, "Passed NULL to three_print_error\n",
			ft_strlen("Passed NULL to three_print_error\n"));
	write(2, str, ft_strlen(str));
	write(2, str2, ft_strlen(str2));
	write(2, "\n", ft_strlen("\n"));
	exit(EXIT_SUCCESS);
}

