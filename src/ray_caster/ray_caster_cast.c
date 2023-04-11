/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster_cast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/04/08 16:54:50 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_caster.h"

int	get_sprite_index(t_collinfo *collinfo)
{
	if (collinfo->axis == X_COLLISION)
	{
		if (collinfo->collision.x > collinfo->collider.x)
			return (EAST);
		return (WEST);
	}
	else
	{
		if (collinfo->collision.y > collinfo->collider.y)
			return (NORTH);
		return (SOUTH);
	}
}

void	set_sprite_index(t_ray_caster *rc, t_collinfo *collinfo)
{
	t_direction	sprite_index;

	sprite_index = get_sprite_index(collinfo);
	rc->vs->sprite = rc->map->sm->sprites[sprite_index];
}

size_t	get_pixels_by_distance(t_ray_caster *rc, t_fpoint collision)
{
	double	hypotenuse;
	double	alpha;
	double	distance;

	alpha = rc->direction + radian(90) - rc->ray.to_cast;
	hypotenuse = fpoint_get_distance(rc->start, collision);
	distance = sin(alpha) * hypotenuse;
	return (rc->vs->screen->size.y / distance);
}

void	ray_caster_cast(t_ray_caster *rc)
{
	t_collinfo	collinfo;
	int			stripe_index;
	size_t			pixels;
	t_point		screen_pos;

	screen_pos = point_init(0, 0);
	rc->num_of_rays = rc->vs->screen->size.x;
	rc->ray.to_cast = rc->direction + radian(FOV_IN_DEGREE / 2);
	while (screen_pos.x < rc->num_of_rays)
	{
		dda(rc->map->map, rc->start, &rc->ray, &collinfo);
		set_sprite_index(rc, &collinfo);
		stripe_index = sprite_get_stripe(rc->vs->sprite, collinfo.collision);
		pixels = get_pixels_by_distance(rc, collinfo.collision);
		screen_pos.y = (SCREEN_SIZE_Y / 2) - (pixels / 2);
		if (!pixels)
		{
			printf("coll \t"); fpoint_print(collinfo.collision); printf("\n");
			printf("pixels: %ld\n", pixels);
			printf("screen: "); point_print(screen_pos); printf("\n");
		}
		vertical_stripe_set_arg(rc->vs, screen_pos, stripe_index, pixels);
		vertical_stripe_draw(rc->vs);
		++screen_pos.x;
		rc->ray.to_cast -= radian(FOV_IN_DEGREE) / \
			(double)rc->num_of_rays;
	}
}
