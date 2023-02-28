/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:12:10 by anonymous         #+#    #+#             */
/*   Updated: 2023/02/28 13:44:39 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

typedef struct s_ray
{
	t_point	x_pos;
	t_point	y_pos;
	double	slope;
	double	intercept;
	double	*incrementor;
	t_angle	to_cast;
}				t_ray;

void	ray_increment(t_ray	*ray_data);

#endif