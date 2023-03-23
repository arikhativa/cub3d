/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:10:14 by anonymous         #+#    #+#             */
/*   Updated: 2023/03/23 12:08:27 by yrabby           ###   ########.fr       */
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

void	dda_set_ray_data(t_ray *ray_data, double alpha, t_player *player)
{
	ray_data->slope = tan(alpha);
	ray_data->intercept = player->pos.y - (player->pos.x * ray_data->slope);
	ray_data->x_pos = player->pos;
	ray_data->y_pos = player->pos;
}
