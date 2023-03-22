/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:36:01 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/16 10:59:46 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

int	sprite_get_pixel_color(t_sprite *s, t_point pos)
{
	char	*pixel;

	pixel = pixel_increment_y(s->pixel, pos.y, s->line_size);
	pixel = pixel_increment_x(pixel, pos.x, s->bits_per_pixel);
	return (*(int *)pixel);
}
