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

// TODO make sure this func is correct and crea unit test for it
// it is agly but working
double	get_first_inc(double pos, double inc)
{
	double	rem;

	rem = fmod(pos, 1);
	if (rem > 0)
	{
		if (1 == inc)
			return ((double)1 - rem);
		else if (-1 == inc)
			return (rem * -1);
	}
	if (rem < 0)
	{
		if (1 == inc)
			return (rem * -1);
		else if (-1 == inc)
			return (((double)1 + rem) * -1);
	}
	return (inc);
}

t_fpoint	ray_get_next_y(t_ray *ray_data)
{
	double		inc;
	t_fpoint	ret;

	ret = fpoint_copy(ray_data->y_pos);
	inc = ray_data->incrementor.y;
	inc = get_first_inc(ret.y, inc);
	ret.y += inc;
	if (INFI != ray_data->slope.type && NEG_INFI != ray_data->slope.type)
		ret.x += (inc / ray_data->slope.value);
	return (ret);
}

t_fpoint	ray_get_next_x(t_ray *ray_data)
{
	double		inc;
	t_fpoint	ret;

	ret = fpoint_copy(ray_data->x_pos);
	inc = ray_data->incrementor.x;
	inc = get_first_inc(ret.x, inc);
	ret.x += inc;
	if (ZERO != ray_data->slope.type && NEG_ZERO != ray_data->slope.type)
		ret.y += (inc * ray_data->slope.value);
	return (ret);
}
