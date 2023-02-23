/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:59:18 by ycarro            #+#    #+#             */
/*   Updated: 2023/02/23 17:12:59 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <collision.h>

int	it_collides(t_ray *ray_data, char **map, t_point *collision)
{
	int	ray_num;

	ray_num = check_in_range(ray_data, map);
	if (ray_num == 0)
	{
		collision->x = ray_data->x_pos.x;
		collision->y = ray_data->x_pos.y;
		return (1);
	}
	if (ray_num == 1)
	{
		collision->x = ray_data->y_pos.x;
		collision->y = ray_data->y_pos.y;
		return (1);
	}
	return (0);
}

int	check_in_range(t_ray *ray_data, char **map)
{
	t_point	collider;

	collider.x = ray_data->x_pos.x / 100;
	collider.y = ray_data->x_pos.y / 100;
	if (map[collider.x][collider.y] == 1)
		return (0);
	collider.x = ray_data->y_pos.x / 100;
	collider.y = ray_data->y_pos.y / 100;
	if (map[collider.x][collider.y] == 1)
		return (1);
	return (-1);
}
