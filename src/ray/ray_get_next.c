/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:50:12 by anonymous         #+#    #+#             */
/*   Updated: 2023/03/19 13:04:18 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_fpoint	ray_get_next_y(t_ray *ray_data)
{
	t_fpoint	ret;

	ret = fpoint_copy(ray_data->y_pos);
	ret.y += (double)ray_data->incrementor.y;
	if (INFI != ray_data->slope.type && NEG_INFI != ray_data->slope.type)
		ret.x += (ray_data->incrementor.y / ray_data->slope.value);
	return (ret);
}

t_fpoint	ray_get_next_x(t_ray *ray_data)
{
	t_fpoint	ret;

	ret = fpoint_copy(ray_data->x_pos);
	ret.x += ray_data->incrementor.x;
	if (ZERO != ray_data->slope.type && NEG_ZERO != ray_data->slope.type)
		ret.y += (ray_data->incrementor.x * ray_data->slope.value);
	return (ret);
}
