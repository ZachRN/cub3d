/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_maths.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 12:09:26 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/11/19 12:12:18 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector_maths.h"

t_vector	rotate_vector(double phi, t_vector vector)
{
	t_vector	ret;

	ret.x = vector.x * cos(phi) - vector.y * sin(phi);
	ret.y = vector.x * sin(phi) + vector.y * cos(phi);
	return (ret);
}

t_vector	add_vector(t_vector a, t_vector b)
{
	t_vector	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return (result);
}

t_vector	subtract_vector(t_vector a, t_vector b)
{
	t_vector	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	return (result);
}