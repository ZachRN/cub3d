/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_errors.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 15:21:43 by znajda        #+#    #+#                 */
/*   Updated: 2022/11/16 16:30:51 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>
#include <unistd.h>

void	extension_error_print(char *error, char *expected, char *input)
{
	write(STDERR_FILENO, "Error\n", ft_strlen("Error\n"));
	if (!error || !expected || !input)
		write(STDERR_FILENO, "Passed NULL to three_print_error\n",
			ft_strlen("Passed NULL to three_print_error\n"));
	write(STDERR_FILENO, error, ft_strlen(error));
	write(STDERR_FILENO, "\nExpected:[", ft_strlen("\nExpected:["));
	write(STDERR_FILENO, expected, ft_strlen(expected));
	write(STDERR_FILENO, "]\nReceived:[", ft_strlen("\n]Received:["));
	write(STDERR_FILENO, input, ft_strlen(input));
	write(STDERR_FILENO,"]\n",ft_strlen("]\n"));
	exit(EXIT_SUCCESS);
}

void	two_strings_error(char *str, char *str2)
{
	write(STDERR_FILENO, "Error\n", ft_strlen("Error\n"));
	if (!str || !str2)
		write(STDERR_FILENO, "Passed NULL to two_strings_error\n",
			ft_strlen("Passed NULL to two_strings_error\n"));
	write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, str2, ft_strlen(str2));
	write(STDERR_FILENO, "\n", ft_strlen("\n"));
	exit(EXIT_SUCCESS);
}

void	one_string_error(char *str)
{
	write(STDERR_FILENO, "Error\n", ft_strlen("Error\n"));
	if (!str)
		write(STDERR_FILENO, "Passed NULL to one_string_error\n",
			ft_strlen("Passed NULL to one_string_error\n"));
	write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, "\n", ft_strlen("\n"));
	exit(EXIT_SUCCESS);
}

