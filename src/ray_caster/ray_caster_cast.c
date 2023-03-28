/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/03/23 11:20:07 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_caster.h"

// TODO this func is a just placement. plz replace with the correct logic
int	get_sprite_index(t_fpoint collision)
{
	int	x;
	int	y;

	x = fmod(collision.x, 4);
	y = fmod(collision.y + 1, 4);
	if (x == 0)
		return (y);
	if (y == 0)
		return (x);
	return (x);
}

void	set_sprite_index(t_ray_caster *rc, t_fpoint collision)
{
	t_direction	sprite_index;

	sprite_index = get_sprite_index(collision);
	rc->vs->sprite = rc->map->sm->sprites[sprite_index];
}

int	get_pixels_by_distance(t_fpoint start, t_fpoint collision)
{
	double	distance;

	distance = fpoint_get_distance(start, collision) + MIN_DISTANCE_CONST;
	return (SCREEN_SIZE_Y / distance);
}

void	ray_caster_cast(t_ray_caster *rc)
{
	t_fpoint	collision;
	int			stripe_index;
	int			pixels;
	t_point		screen_pos;

	screen_pos = point_init(0, 0);
	rc->num_of_rays = SCREEN_SIZE_X;
	rc->ray.to_cast.radians = rc->direction + radian(FOV_IN_DEGREE / 2);
	while (screen_pos.x < rc->num_of_rays)
	{
		dda(rc->map->map, rc->start, &rc->ray, &collision);
		set_sprite_index(rc, collision);
		stripe_index = sprite_get_stripe(rc->vs->sprite, collision);
		pixels = get_pixels_by_distance(rc->start, collision);
		screen_pos.y = (SCREEN_SIZE_Y / 2) - (pixels / 2);
		vertical_stripe_set_arg(rc->vs, screen_pos, stripe_index, pixels);
		vertical_stripe_draw(rc->vs);
		++screen_pos.x;
		rc->ray.to_cast.radians -= radian(FOV_IN_DEGREE) / \
			(double)rc->num_of_rays;
	}
}
