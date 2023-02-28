/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:48:17 by ycarro            #+#    #+#             */
/*   Updated: 2023/02/28 12:23:36 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda.h"

void	dda(char **map, t_player *p, t_ray	*ray_data, t_point *collision)
{
	(void)map;
	(void)collision;
	dda_set_incrementor(ray_data, ray_data->to_cast.radians);
	dda_set_ray_data(ray_data, ray_data->to_cast.radians, p);
}

void	dda_set_incrementor(t_ray *ray_data, double alpha)
{
	ray_data->incrementor = ft_calloc(2, sizeof(double));
	while (alpha > (2.0 * M_PI))
		alpha -= (2.0 * M_PI);
	if (alpha >= ((3.0 / 2.0) * M_PI))
	{
		ray_data->incrementor[0] = 1;
		ray_data->incrementor[1] = -1;
	}
	else if (alpha >= M_PI)
	{
		ray_data->incrementor[0] = -1;
		ray_data->incrementor[1] = -1;
	}
	else if (alpha >= ((1.0 / 2.0) * M_PI))
	{
		ray_data->incrementor[0] = -1;
		ray_data->incrementor[1] = 1;
	}
	else
	{
		ray_data->incrementor[0] = 1;
		ray_data->incrementor[1] = 1;
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
