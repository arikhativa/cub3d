/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:10:14 by anonymous         #+#    #+#             */
/*   Updated: 2023/03/24 17:19:50 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda.h"

void	dda(char **map, t_player *p, t_ray *ray_data, t_fpoint *collision)
{
	dda_set_incrementor(ray_data, ray_data->to_cast.radians);
	dda_set_ray_data(ray_data, ray_data->to_cast.radians, p);
	while (is_collides(ray_data, map, collision) == NO_COLLISION)
		ray_increment(ray_data);
}

void	dda_set_incrementor(t_ray *ray_data, double alpha)
{
	t_direction	dir;

	alpha = radian_set_boundaries(alpha);
	dir = radian_get_direction(alpha);
	if (NORTH == dir)
		ray_data->incrementor = point_init(0, -1);
	else if (SOUTH == dir)
		ray_data->incrementor = point_init(0, 1);
	else if (EAST == dir)
		ray_data->incrementor = point_init(1, 0);
	else if (WEST == dir)
		ray_data->incrementor = point_init(-1, 0);
	else if (NE == dir)
		ray_data->incrementor = point_init(1, -1);
	else if (NW == dir)
		ray_data->incrementor = point_init(-1, -1);
	else if (SW == dir)
		ray_data->incrementor = point_init(-1, 1);
	else if (SE == dir)
		ray_data->incrementor = point_init(1, 1);
}

static void	init_slope(t_ray *ray_data, double alpha)
{
	t_direction	dir;

	ray_data->slope.type = VALUE;
	ray_data->slope.value = tan(alpha) * -1;
	dir = radian_get_direction(alpha);
	if (NORTH == dir)
		ray_data->slope.type = NEG_INFI;
	else if (SOUTH == dir)
		ray_data->slope.type = INFI;
	else if (EAST == dir)
		ray_data->slope.type = ZERO;
	else if (WEST == dir)
		ray_data->slope.type = NEG_ZERO;
}

// TODO I added the -1 since our matrix if flipped (y axis is inverted)
void	dda_set_ray_data(t_ray *ray_data, double alpha, t_player *player)
{
	init_slope(ray_data, alpha);
	ray_data->intercept = player->pos.y - \
		(player->pos.x * ray_data->slope.value);
	ray_data->x_pos = point_to_fpoint(player->pos);
	ray_data->y_pos = point_to_fpoint(player->pos);
}
