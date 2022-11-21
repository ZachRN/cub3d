/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 16:40:27 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/11/21 14:12:47 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMSET_H
# define FT_MEMSET_H

# include <unistd.h>

void	*ft_memset(void *s, int c, size_t n);

#endif