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
		ray_data->y_pos.x += ray_data->incrementor.y;
		ray_data->y_pos.y = (ray_data->slope.value * ray_data->y_pos.x + ray_data->intercept);
		// ray_data->y_pos.y += ray_data->incrementor.y;
		// ray_data->y_pos.x = (ray_data->slope.value * ray_data->y_pos.y + ray_data->intercept);
	}
}

t_bool	should_inc_x(t_ray *ray_data)
{
	// t_fpoint	start;
	// t_fpoint	end;
	// double		distance_x;
	// double		distance_y;

	if (INFI == ray_data->slope.type || NEG_INFI == ray_data->slope.type)
		return (FALSE);
	if (ZERO == ray_data->slope.type || NEG_ZERO == ray_data->slope.type)
		return (TRUE);
	if (ray_data->incrementor.x == POSITIVE)
	{
		// start = ray_data->x_pos;
		// end = ray_data->y_pos;
		// distance_x = fpoint_get_distance(start, end);
		
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

void	ray_set_incrementor(t_ray *ray_data, double alpha)
{
	t_direction	dir;

	alpha = radian_set_boundaries(alpha);
	dir = radian_get_direction(alpha);
	if (NORTH == dir)
		ray_data->incrementor = point_init(0, 1);
	else if (SOUTH == dir)
		ray_data->incrementor = point_init(0, -1);
	else if (EAST == dir)
		ray_data->incrementor = point_init(1, 0);
	else if (WEST == dir)
		ray_data->incrementor = point_init(-1, 0);
	else if (NE == dir)
		ray_data->incrementor = point_init(1, 1);
	else if (NW == dir)
		ray_data->incrementor = point_init(-1, 1);
	else if (SW == dir)
		ray_data->incrementor = point_init(-1, -1);
	else if (SE == dir)
		ray_data->incrementor = point_init(1, -1);
}

static void	init_slope(t_ray *ray_data, double alpha)
{
	t_direction	dir;

	ray_data->slope.type = VALUE;
	ray_data->slope.value = tan(alpha);
	dir = radian_get_perfect_direction(alpha);
	if (NORTH == dir)
		ray_data->slope.type = INFI;
	else if (SOUTH == dir)
		ray_data->slope.type = NEG_INFI;
	else if (EAST == dir)
		ray_data->slope.type = ZERO;
	else if (WEST == dir)
		ray_data->slope.type = NEG_ZERO;
	else if (PERFECT_NE == dir)
		ray_data->slope.value = 1;
	else if (PERFECT_NW == dir)
		ray_data->slope.value = -1;
	else if (PERFECT_SW == dir)
		ray_data->slope.value = 1;
	else if (PERFECT_SE == dir)
		ray_data->slope.value = -1;
}

void	rey_init(t_ray *ray_data, double alpha, t_point player_pos)
{
	init_slope(ray_data, alpha);
	ray_data->intercept = player_pos.y - \
		(player_pos.x * ray_data->slope.value);
	ray_data->x_pos = point_to_fpoint(player_pos);
	ray_data->y_pos = point_to_fpoint(player_pos);
}

