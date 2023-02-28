/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:10:14 by anonymous         #+#    #+#             */
/*   Updated: 2023/02/28 13:57:23 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda.h"

void	dda(char **map, t_player *p, t_ray	*ray_data, t_point *collision)
{
	dda_set_incrementor(ray_data, ray_data->to_cast.radians);
	dda_set_ray_data(ray_data, ray_data->to_cast.radians, p);
	while (!is_collides(ray_data, map, collision))
	{
		ray_increment(ray_data);
	}
}

void	dda_set_incrementor(t_ray *ray_data, double alpha)
{
	while (alpha > (2.0 * M_PI))
		alpha -= (2.0 * M_PI);
	if (alpha >= ((3.0 / 2.0) * M_PI))
	{
		ray_data->incrementor.x = 1;
		ray_data->incrementor.y = -1;
	}
	else if (alpha >= M_PI)
	{
		ray_data->incrementor.x = -1;
		ray_data->incrementor.y = -1;
	}
	else if (alpha >= ((1.0 / 2.0) * M_PI))
	{
		ray_data->incrementor.x = -1;
		ray_data->incrementor.y = 1;
	}
	else
	{
		ray_data->incrementor.x = 1;
		ray_data->incrementor.y = 1;
	}
}

void	dda_set_ray_data(t_ray *ray_data, double alpha, t_player *player)
{
	ray_data->slope = tan(alpha);
	ray_data->intercept = player->pos.y - (player->pos.x * ray_data->slope);
	ray_data->x_pos.x = player->pos.x;
	ray_data->x_pos.y = player->pos.y;
	ray_data->y_pos.x = player->pos.x;
	ray_data->y_pos.x = player->pos.y;
}
