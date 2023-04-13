/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpoint.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/03/24 17:24:08 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FPOINT_H
# define FPOINT_H

# include <math.h>

# include "point.h"

# define EPSILON 0.0000000000001

typedef struct s_fpoint
{
	double	x;
	double	y;
}				t_fpoint;

t_fpoint	fpoint_init(double x, double y);
t_fpoint	fpoint_copy(t_fpoint src);
t_point		fpoint_to_point(t_fpoint p);
t_fpoint	point_to_fpoint(t_point p);
void		fpoint_print(t_fpoint p);
double		fpoint_get_distance(t_fpoint p1, t_fpoint p2);
t_bool		fpoint_equal(t_fpoint a, t_fpoint b);
t_bool		fpoint_is_corner(t_fpoint p);

#endif
