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
	if (should_inc_x(ray_data))
	{
		ray_data->x_pos.x += ray_data->incrementor.x;
		ray_data->x_pos.y = (ray_data->slope.value * ray_data->x_pos.x \
			+ ray_data->intercept);
	}
	else
	{
		if (INFI == ray_data->slope.type || NEG_INFI == ray_data->slope.type)
		{
			ray_data->y_pos.y += ray_data->incrementor.y;
			return ;
		}
		// ray_data->y_pos.x += ray_data->incrementor.y;
		// ray_data->y_pos.y = (ray_data->slope.value * ray_data->y_pos.x + ray_data->intercept);
		ray_data->y_pos.y += ray_data->incrementor.y;
		ray_data->y_pos.x = (ray_data->slope.value * ray_data->y_pos.y 	+ ray_data->intercept);
	}
}


t_bool	should_inc_x(t_ray *ray_data)
{
	if (ZERO == ray_data->slope.type || NEG_ZERO == ray_data->slope.type)
		return (TRUE);
	if (ray_data->incrementor.x == POSITIVE)
	{
		if ((int)ray_data->x_pos.x <= (int)ray_data->y_pos.x)
			return (TRUE);
	}
	if (ray_data->incrementor.x == NEGATIVE)
	{
		if ((int)ray_data->x_pos.x >= (int)ray_data->y_pos.x)
			return (TRUE);
	}
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
