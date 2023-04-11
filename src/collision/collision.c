/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:59:18 by ycarro            #+#    #+#             */
/*   Updated: 2023/04/11 15:44:58 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collision.h"

int	is_collides(t_ray *ray_data, char **map, t_collinfo *collinfo)
{
	int	ray_num;

	ray_num = check_in_range(ray_data, map, collinfo);
	if (ray_num == X_COLLISION)
	{
		collinfo->collision = fpoint_copy(ray_data->x_pos);
		collinfo->axis = X_COLLISION;
		return (X_COLLISION);
	}
	if (ray_num == Y_COLLISION)
	{
		collinfo->collision = fpoint_copy(ray_data->y_pos);
		collinfo->axis = Y_COLLISION;
		return (Y_COLLISION);
	}
	return (NO_COLLISION);
}

t_collision	check_in_range(t_ray *ray_data, char **map, t_collinfo *collinfo)
{
	collinfo->collider = fpoint_to_point(ray_data->x_pos);
	if (!(fpoint_equal(ray_data->start, ray_data->x_pos)) && \
		ray_data->incrementor.x == -1)
		collinfo->collider.x--;
	if (map[collinfo->collider.y][collinfo->collider.x] == WALL_CHAR)
		return (X_COLLISION);
	collinfo->collider = fpoint_to_point(ray_data->y_pos);
	if (!(fpoint_equal(ray_data->start, ray_data->y_pos)) && \
		ray_data->incrementor.y == -1)
		collinfo->collider.y--;
	if (map[collinfo->collider.y][collinfo->collider.x] == WALL_CHAR)
		return (Y_COLLISION);
	return (NO_COLLISION);
}
