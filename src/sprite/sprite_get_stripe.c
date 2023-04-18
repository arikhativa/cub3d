/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_get_stripe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/04/18 14:31:49 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

// TODO this func is just a placement. plz replace with the correct logic
double	get_sprite_index_by_axis(t_sprite *s, t_fpoint collision)
{
	double	x;
	double	y;

	x = fmod(collision.x, 1);
	y = fmod(collision.y, 1);
	if (x == 0)
	{
		if (WEST == s->index)
			return (1 - y);
		return (y);
	}
	if (y == 0)
	{
		if (NORTH == s->index)
			return (1 - x);
		return (x);
	}
	return (x);
}

int	sprite_get_stripe(t_sprite *s, t_fpoint collision_point)
{
	double	collision;
	double	x;

	collision = get_sprite_index_by_axis(s, collision_point);
	if (0 > collision)
		collision *= -1;
	x = fmod(collision, 1.0);
	x = x * s->size.x;
	return ((int)x);
}
