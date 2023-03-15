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

static void	draw_line(t_screen *screen, int y, int color)
{
	int	x;

	x = 0;
	while (x < screen->size.x)
	{
		screen_color_pixel(screen, point_init(x, y), color);
		++x;
	}
}

void	screen_draw_background(t_screen *screen, int celling, int floor)
{
	int	y;

	y = 0;
	while (y < (screen->size.y / 2))
	{
		draw_line(screen, y, celling);
		++y;
	}
	while (y < (screen->size.y))
	{
		draw_line(screen, y, floor);
		++y;
	}
}
