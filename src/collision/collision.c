/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:59:18 by ycarro            #+#    #+#             */
/*   Updated: 2023/04/11 16:53:08 by ycarro           ###   ########.fr       */
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
	get_map_index(ray_data, ray_data->x_pos, \
		ray_data->incrementor.x, &collinfo->collider.x);
	corner_check(ray_data->to_cast, &collinfo->collider.y);
	if (map[collinfo->collider.y][collinfo->collider.x] == WALL_CHAR)
		return (X_COLLISION);
	collinfo->collider = fpoint_to_point(ray_data->y_pos);
	get_map_index(ray_data, ray_data->y_pos, \
		ray_data->incrementor.y, &collinfo->collider.y);
	corner_check(ray_data->to_cast, &collinfo->collider.x);
	if (map[collinfo->collider.y][collinfo->collider.x] == WALL_CHAR)
		return (Y_COLLISION);
	return (NO_COLLISION);
}

void	get_map_index(t_ray *ray_data, t_fpoint pos, \
	int incrementor, int *point)
{
	if (!(fpoint_equal(ray_data->start, pos)))
		if (incrementor == -1)
			(*point)--;
	if (radian(225) == ray_data->to_cast)
		(*point)--;
}

void	corner_check(double alpha, int *point)
{
	if (radian(225) == alpha)
		(*point)--;
}
