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

# include "point.h"
# include "angle.h"

# define POSITIVE	1
# define NEGATIVE	-1

typedef struct s_ray
{
	t_point	x_pos;
	t_point	y_pos;
	double	slope;
	double	intercept;
	t_point	incrementor;
	t_angle	to_cast;
}				t_ray;

void	ray_increment(t_ray	*ray_data);
t_bool	should_inc_x(t_ray *ray_data);

#endif