/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:12:10 by anonymous         #+#    #+#             */
/*   Updated: 2023/03/02 15:34:55 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "radian.h"
# include "fpoint.h"
# include "point.h"
# include "angle.h"
# include "slope.h"

# define POSITIVE	1
# define NEGATIVE	-1

typedef struct s_ray
{
	t_fpoint	x_pos;
	t_fpoint	y_pos;
	t_slope		slope;
	double		intercept;
	t_point		incrementor;
	t_angle		to_cast;
}				t_ray;

void		ray_set_incrementor(t_ray *ray_data, double alpha);
void		ray_increment(t_ray	*ray_data);
t_bool		should_inc_x(t_ray *ray_data);
void		ray_print(t_ray *r);
t_fpoint	increment_x(t_ray *ray_data);
t_fpoint	increment_y(t_ray *ray_data);
void		rey_init(t_ray *ray_data, double alpha, t_point player_pos);


#endif