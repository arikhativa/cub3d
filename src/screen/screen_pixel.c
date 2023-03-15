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

#include "screen.h"

void	screen_color_pixel(t_screen *s, t_point pos, int color)
{
	char    *pixel;

	pixel = pixel_increment_y(s->pixel, pos.y, s->line_size);
	pixel = pixel_increment_x(pixel, pos.x, s->bits_per_pixel);
	*(int *)pixel = color;
}
