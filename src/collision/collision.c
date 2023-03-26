/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:59:18 by ycarro            #+#    #+#             */
/*   Updated: 2023/03/24 17:18:39 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collision.h"

int	is_collides(t_ray *ray_data, char **map, t_fpoint *collision)
{
	int	ray_num;

	ray_num = check_in_range(ray_data, map);
	if (ray_num == 0)
	{
		collision->x = ray_data->x_pos.x;
		collision->y = ray_data->x_pos.y;
		return (X_COLLISION);
	}
	if (ray_num == 1)
	{
		collision->x = ray_data->y_pos.x;
		collision->y = ray_data->y_pos.y;
		return (Y_COLLISION);
	}
	return (NO_COLLISION);
}

#include "tab.h"

t_collision	check_in_range(t_ray *ray_data, char **map)
{
	t_point	collider;

	collider = fpoint_to_point(ray_data->x_pos);
	printf(" ---- \n");
	printf("X: ");
	fpoint_print(ray_data->x_pos);
	printf("\t");
	point_print(collider);
	printf("\n");
	if (map[collider.y][collider.x] == WALL_CHAR)
		return (X_COLLISION);
	collider = fpoint_to_point(ray_data->y_pos);
	printf("Y: ");
	fpoint_print(ray_data->y_pos);
	printf("\t");
	point_print(collider);
	printf("\n");
	printf(" ---- \n");
	if (map[collider.y][collider.x] == WALL_CHAR)
		return (Y_COLLISION);
	return (NO_COLLISION);
}
