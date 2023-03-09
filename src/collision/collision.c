/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:59:18 by ycarro            #+#    #+#             */
/*   Updated: 2023/02/28 12:38:51 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collision.h"

t_bool	is_collides(t_ray *ray_data, char **map, t_point *collision)
{
	int	ray_num;

	ray_num = check_in_range(ray_data, map);
	if (ray_num == 0)
	{
		collision->x = ray_data->x_pos.x;
		collision->y = ray_data->x_pos.y;
		return (TRUE);
	}
	if (ray_num == 1)
	{
		collision->x = ray_data->y_pos.x;
		collision->y = ray_data->y_pos.y;
		return (TRUE);
	}
	return (FALSE);
}

t_collision	check_in_range(t_ray *ray_data, char **map)
{
	t_point	collider;

	collider.x = ray_data->x_pos.x / 100;
	collider.y = ray_data->x_pos.y / 100;
	if (map[collider.x][collider.y] == WALL_CHAR)
		return (X_COLLISION);
	collider.x = ray_data->y_pos.x / 100;
	collider.y = ray_data->y_pos.y / 100;
	if (map[collider.x][collider.y] == WALL_CHAR)
		return (Y_COLLISION);
	return (NO_COLLISION);
}