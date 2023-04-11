/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:59:18 by ycarro            #+#    #+#             */
/*   Updated: 2023/04/08 16:52:07 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collision.h"

int	is_collides(t_ray *ray_data, char **map, t_collinfo *collinfo)
{
	int	ray_num;

	ray_num = check_in_range(ray_data, map, collinfo);
	if (ray_num == X_COLLISION)
	{
		collinfo->pos = fpoint_copy(ray_data->x_pos);
		collinfo->axis = X_COLLISION;
		return (X_COLLISION);
	}
	if (ray_num == Y_COLLISION)
	{
		collinfo->pos = fpoint_copy(ray_data->y_pos);
		collinfo->axis = Y_COLLISION;
		return (Y_COLLISION);
	}
	return (NO_COLLISION);
}

void xxx(t_ray *r, t_collinfo *collinfo)
{
	double	alpha;

	if (fpoint_equal(r->start, r->x_pos))
		return ;
	alpha = r->to_cast;
	if (radian_is_north_west(alpha) || radian_is_south_west(alpha))
		--collinfo->coll_index.x;
	if (radian(225) == alpha)
		--collinfo->coll_index.y;
}

void yyy(t_ray *r, t_collinfo *collinfo)
{
	double	alpha;

	if (fpoint_equal(r->start, r->y_pos))
		return ;
	alpha = r->to_cast;
	if (radian_is_south_east(alpha) || radian_is_south_west(alpha))
		--collinfo->coll_index.y;
	if (radian(225) == alpha)
		--collinfo->coll_index.x;
}

t_collision	check_in_range(t_ray *ray_data, char **map, t_collinfo *collinfo)
{
	printf("X: x: %f, y: %f\n", ray_data->x_pos.x, ray_data->x_pos.y);
	collinfo->coll_index = fpoint_to_point(ray_data->x_pos);
	xxx(ray_data, collinfo);
	if (map[collinfo->coll_index.y][collinfo->coll_index.x] == WALL_CHAR)
		return (X_COLLISION);
	printf("Y: x: %f, y: %f\n", ray_data->y_pos.x, ray_data->y_pos.y);
	collinfo->coll_index = fpoint_to_point(ray_data->y_pos);
	yyy(ray_data, collinfo);
	if (map[collinfo->coll_index.y][collinfo->coll_index.x] == WALL_CHAR)
		return (Y_COLLISION);
	return (NO_COLLISION);
}
