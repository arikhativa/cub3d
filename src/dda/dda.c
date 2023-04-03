/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:10:14 by anonymous         #+#    #+#             */
/*   Updated: 2023/03/30 13:18:37 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda.h"

void	dda(char **map, t_fpoint start, t_ray *ray_data, t_collinfo *collinfo)
{
	ray_set_incrementor(ray_data, ray_data->to_cast.radians);
	rey_init(ray_data, ray_data->to_cast.radians, start);
	while (is_collides(ray_data, map, collinfo) == NO_COLLISION)
		ray_increment(ray_data);
}
