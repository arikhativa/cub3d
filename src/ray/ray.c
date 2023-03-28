/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:50:12 by anonymous         #+#    #+#             */
/*   Updated: 2023/03/19 13:04:18 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	ray_increment(t_ray	*ray_data)
{
	t_fpoint	next;

	if (should_inc_x(ray_data))
	{
		next = ray_get_next_x(ray_data);
		ray_data->x_pos = fpoint_copy(next);
	}
	else
	{
		next = ray_get_next_y(ray_data);
		ray_data->y_pos = fpoint_copy(next);
	}
}

t_bool	should_inc_x(t_ray *ray_data)
{
	t_fpoint	next_x;
	t_fpoint	next_y;
	double		distance_x;
	double		distance_y;

	if (ZERO == ray_data->slope.type || NEG_ZERO == ray_data->slope.type)
		return (TRUE);
	if (INFI == ray_data->slope.type || NEG_INFI == ray_data->slope.type)
		return (FALSE);
	next_x = ray_get_next_x(ray_data);
	next_y = ray_get_next_y(ray_data);
	distance_x = fpoint_get_distance(ray_data->start, next_x);
	distance_y = fpoint_get_distance(ray_data->start, next_y);
	if (distance_x < distance_y)
		return (TRUE);
	return (FALSE);
}

void	ray_print(t_ray *r)
{
	printf("ray: \nslope: %f, intercept: %f, to_cast: %f\n", \
		r->slope.value, r->intercept, r->to_cast.radians);
	printf("incrementor: ");
	point_print(r->incrementor);
	printf("\n");
	printf("x: ");
	fpoint_print(r->x_pos);
	printf("\n");
	printf("y: ");
	fpoint_print(r->y_pos);
	printf("\n");
}
