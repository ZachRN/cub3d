/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 16:01:42 by znajda        #+#    #+#                 */
/*   Updated: 2022/11/16 16:04:55 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"
#include "cub3d_errors.h"

static int	trimmer(char const *s1, char const *set, int i)
{
	int	j;

	j = 0;
	while (set[j] != '\0')
	{
		if (s1[i] == set[j])
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		front;
	int		end;
	int		i;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	front = 0;
	i = 0;
	end = ft_strlen(s1);
	while (trimmer(s1, set, front) && s1[front])
		front++;
	while (trimmer(s1, set, (end - 1)) && end > front)
		end--;
	str = (char *)malloc(sizeof(char) * (end - front + 1));
	if (!str)
		two_strings_error(MALLOC_ERROR, "ft_strtrim.c; line 47");
	while (front < end)
	{
		str[i] = s1[front];
		front++;
		i++;
	}
	str[i] = '\0';
	return (str);
}