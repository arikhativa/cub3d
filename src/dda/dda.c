/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:10:14 by anonymous         #+#    #+#             */
/*   Updated: 2023/03/24 17:19:50 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda.h"

void	dda(char **map, t_player *p, t_ray *ray_data, t_fpoint *collision)
{
	ray_set_incrementor(ray_data, ray_data->to_cast.radians);
	rey_init(ray_data, ray_data->to_cast.radians, point_to_fpoint(p->pos));
	while (is_collides(ray_data, map, collision) == NO_COLLISION)
		ray_increment(ray_data);
}
