/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 15:53:00 by znajda        #+#    #+#                 */
/*   Updated: 2022/11/16 15:53:01 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_calloc.h"

char	**free_my_lines(char **str)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static int	wordinput(char const *s, int start, char **str, char c)
{
	int	i;
	int	line;

	i = 0;
	line = 0;
	while (str[line][0])
		line++;
	while (s[start] != c && s[start])
	{
		str[line][i] = s[start];
		start++;
		i++;
	}
	str[line][i] = '\0';
	return (start);
}

static char	**wordfill(char const *s, char c, char **str)
{
	int	start;
	int	end;
	int	line;

	start = 0;
	line = 0;
	while (s[start] && s[start] == c)
		start++;
	end = start;
	while (s[end])
	{
		end++;
		if ((s[end] == c || !s[end]) && s[end - 1] != c)
		{
			str[line] = (char *)ft_calloc((end - start + 1), sizeof(char));
			if (!str[line])
				exit(1);
			wordinput(s, start, str, c);
			while (s[end] == c && s[end])
				end++;
			start = end;
			line++;
		}
	}
	return (str);
}

static int	word_amount(const char *s, char c)
{
	int	total;
	int	pos;

	pos = 0;
	total = 0;
	while (s[pos] && s[pos] == c)
		pos++;
	while (s[pos])
	{
		pos++;
		if ((s[pos] == c || !s[pos]) && s[pos - 1] != c)
			total++;
	}
	return (total);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		words;

	if (!s)
		return (NULL);
	words = word_amount(s, c);
	str = (char **)malloc((words + 1) * sizeof(char *));
	if (!str)
		exit(1);
	str[words] = NULL;
	str = wordfill(s, c, str);
	if (!str)
		return (NULL);
	return (str);
}