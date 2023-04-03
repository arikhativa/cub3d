/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/15 13:55:57 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vertical_stripe.h"

void	vertical_stripe_draw(t_vertical_stripe *vs)
{
	t_point	sprite_pos;
	double	sprite_y;
	double	inc;
	int		color;

	inc = vs->sprite->size.y / vs->num_of_pixels;
	sprite_y = 0;
	while (vs->num_of_pixels)
	{
		sprite_pos = point_init(vs->sprite_x_pos, sprite_y);
		color = sprite_get_pixel_color(vs->sprite, sprite_pos);
		screen_color_pixel(vs->screen, vs->screen_pos, color);
		sprite_y += inc;
		++vs->screen_pos.y;
		--vs->num_of_pixels;
	}
}
