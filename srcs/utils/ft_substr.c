/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 14:36:13 by znajda        #+#    #+#                 */
/*   Updated: 2022/11/16 16:19:23 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "cub3d_errors.h"
#include "ft_strlen.h"

static void	fill(char const *s, size_t len, char *str, size_t start)
{
	size_t	i;
	size_t	x;

	x = ft_strlen(s);
	i = 0;
	while (start < x && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			x;

	if (!s)
		return (NULL);
	x = ft_strlen(s);
	if (len > x)
		len = x;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		two_strings_error(MALLOC_ERROR, "ft_substr.c; line 41");
	if (start >= x)
	{
		str[0] = '\0';
		return (str);
	}
	fill(s, len, str, start);
	return (str);
}
