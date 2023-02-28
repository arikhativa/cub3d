/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:12:10 by anonymous         #+#    #+#             */
/*   Updated: 2023/02/28 14:01:17 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "dda.h"

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
int		ray_differs_in_x(t_ray *ray_data);

#endif