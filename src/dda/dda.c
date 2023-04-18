/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:10:14 by anonymous         #+#    #+#             */
/*   Updated: 2023/04/18 14:09:37 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda.h"

void	dda(char **map, t_fpoint start, t_ray *ray_data, t_collinfo *collinfo)
{
	ray_set_incrementor(ray_data, ray_data->to_cast);
	rey_init(ray_data, ray_data->to_cast, start);
	while (is_collides(ray_data, map, collinfo) == NO_COLLISION)
		ray_increment(ray_data);
}

t_bool	dda_is_wall_near(char **map, t_fpoint start, double dir)
{
	t_ray		ray_data;
	t_collinfo	collinfo;
	double		dist;

	ray_data.to_cast = dir;
	dda(map, start, &ray_data, &collinfo);
	dist = fpoint_get_distance(start, collinfo.collision);
	return (dist < 1.0 && dist > 0.0);
}
