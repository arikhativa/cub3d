/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:59:18 by ycarro            #+#    #+#             */
/*   Updated: 2023/04/12 12:02:09 by ycarro           ###   ########.fr       */
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


void	get_map_index_x(t_ray *r, char **map, t_collinfo *collinfo)
{
	if (fpoint_is_corner(r->x_pos))
		collinfo->collider = get_index_by_corner_type(map, r->x_pos);
	else
		get_map_index(r, r->x_pos, r->incrementor.x, &collinfo->collider.x);
}

void	get_map_index_y(t_ray *r, char **map, t_collinfo *collinfo)
{
	if (fpoint_is_corner(r->y_pos))
		collinfo->collider = get_index_by_corner_type(map, r->y_pos);
	else
		get_map_index(r, r->y_pos, r->incrementor.y, &collinfo->collider.y);
}

void	get_map_index(t_ray *ray_data, t_fpoint pos, int inc, int *point)
{
	if (!(fpoint_equal(ray_data->start, pos)))
		if (inc == -1)
			(*point)--;
}

t_collision	check_in_range(t_ray *ray_data, char **map, t_collinfo *collinfo)
{
	collinfo->collider = fpoint_to_point(ray_data->x_pos);
	get_map_index_x(ray_data, map, collinfo);
	if (map[collinfo->collider.y][collinfo->collider.x] == WALL_CHAR)
		return (X_COLLISION);
	collinfo->collider = fpoint_to_point(ray_data->y_pos);
	get_map_index_y(ray_data, map, collinfo);
	if (map[collinfo->collider.y][collinfo->collider.x] == WALL_CHAR)
		return (Y_COLLISION);
	return (NO_COLLISION);
}
