/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:50:12 by anonymous         #+#    #+#             */
/*   Updated: 2023/04/08 16:06:47 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	ray_set_incrementor(t_ray *ray_data, double alpha)
{
	alpha = radian_set_boundaries(alpha);
	ray_data->dir = radian_get_direction(alpha);
	if (NORTH == ray_data->dir)
		ray_data->incrementor = point_init(0, 1);
	else if (SOUTH == ray_data->dir)
		ray_data->incrementor = point_init(0, -1);
	else if (EAST == ray_data->dir)
		ray_data->incrementor = point_init(1, 0);
	else if (WEST == ray_data->dir)
		ray_data->incrementor = point_init(-1, 0);
	else if (NE == ray_data->dir)
		ray_data->incrementor = point_init(1, 1);
	else if (NW == ray_data->dir)
		ray_data->incrementor = point_init(-1, 1);
	else if (SW == ray_data->dir)
		ray_data->incrementor = point_init(-1, -1);
	else if (SE == ray_data->dir)
		ray_data->incrementor = point_init(1, -1);
}

static void	init_slope(t_ray *ray_data, double alpha)
{
	t_direction	dir;

	ray_data->slope.type = VALUE;
	ray_data->slope.value = tan(alpha);
	dir = radian_get_direction(alpha);
	if (NORTH == dir)
		ray_data->slope.type = INFI;
	else if (SOUTH == dir)
		ray_data->slope.type = NEG_INFI;
	else if (EAST == dir)
		ray_data->slope.type = ZERO;
	else if (WEST == dir)
		ray_data->slope.type = NEG_ZERO;
}

void	rey_init(t_ray *ray_data, double alpha, t_fpoint player_pos)
{
	ray_data->start = fpoint_copy(player_pos);
	init_slope(ray_data, alpha);
	ray_data->intercept = player_pos.y - \
		(player_pos.x * ray_data->slope.value);
	ray_data->x_pos = fpoint_copy(player_pos);
	ray_data->y_pos = fpoint_copy(player_pos);
}
