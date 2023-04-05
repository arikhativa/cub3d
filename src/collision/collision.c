/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:59:18 by ycarro            #+#    #+#             */
/*   Updated: 2023/04/05 20:33:57 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collision.h"

int	is_collides(t_ray *ray_data, char **map, t_collinfo *collinfo)
{
	int	ray_num;

	ray_num = check_in_range(ray_data, map);
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

t_collision	check_in_range(t_ray *ray_data, char **map)
{
	t_point	collider;

	collider = fpoint_to_point(ray_data->x_pos);
	if (ray_data->incrementor.x == -1)
		collider.x--;
	if (map[collider.y][collider.x] == WALL_CHAR)
		return (X_COLLISION);
	collider = fpoint_to_point(ray_data->y_pos);
	if (ray_data->incrementor.y == -1)
		collider.y--;
	if (map[collider.y][collider.x] == WALL_CHAR)
		return (Y_COLLISION);
	return (NO_COLLISION);
}
