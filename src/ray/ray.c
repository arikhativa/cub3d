/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:50:12 by anonymous         #+#    #+#             */
/*   Updated: 2023/02/28 13:30:21 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda.h"

void	ray_increment(t_ray	*ray_data)
{
	if (ray_differs_in_x(ray_data))
	{
		ray_data->x_pos.x += (double)(ray_data->incrementor.x * 100);
		ray_data->x_pos.y = (ray_data->slope * ray_data->x_pos.x \
			+ ray_data->intercept);
	}
	else
	{
		ray_data->y_pos.x += (double)(ray_data->incrementor.y * 100);
		ray_data->y_pos.y = (ray_data->slope * ray_data->y_pos.x \
			+ ray_data->intercept);
	}
}
