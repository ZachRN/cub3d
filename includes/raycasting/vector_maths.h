/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_maths.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 12:10:32 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/11/19 12:13:07 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_MATHS_H
# define VECTOR_MATHS_H

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

t_vector	rotate_vector(double phi, t_vector vector);
t_vector	add_vector(t_vector a, t_vector b);
t_vector	subtract_vector(t_vector a, t_vector b);

#endif
