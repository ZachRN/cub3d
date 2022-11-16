/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 15:53:35 by znajda        #+#    #+#                 */
/*   Updated: 2022/11/16 16:05:41 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub3d_errors.h"

static void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n)
	{
		*str = '\0';
		str++;
		n--;
	}
}

void	*ft_calloc(size_t nmeb, size_t size)
{
	void	*memory;

	if (nmeb == 0 || size == 0)
	{
		nmeb = 1;
		size = 1;
	}
	memory = malloc(nmeb * size);
	if (!memory)
		two_strings_error(MALLOC_ERROR, "ft_calloc.c; line 38");
	ft_bzero(memory, (nmeb * size));
	return (memory);
}