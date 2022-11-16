/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   extension_check.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 15:33:32 by znajda        #+#    #+#                 */
/*   Updated: 2022/11/15 16:45:41 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <unistd.h>

char	*extension_check(char *str, char *ext)
{
	int	str_len;
	int	ext_len;

	if (!str || !ext)
		return (NULL);
	str_len = ft_strlen(str);
	ext_len = ft_strlen(ext);
	if (str_len <= ext_len)	
		return (NULL);
	while (ext_len >= 0)
	{
		if (str[str_len] != ext[ext_len])
			return (NULL);
		str_len--;
		ext_len--;
	}
	return (str);
}
