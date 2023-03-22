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

#include "game.h"

void	draw_adjusted_sprite(t_game *g, t_point screen_pos, \
	double num_of_pixels)
{
	double	sprite_x;
	double	inc;
	double	tmp;

	sprite_x = 0;
	tmp = num_of_pixels;
	g->vs->sprite = g->map->sm->sprites[0];
	inc = g->vs->sprite->size.x / num_of_pixels;
	while (num_of_pixels)
	{
		vertical_stripe_set_arg(g->vs, screen_pos, sprite_x, tmp);
		vertical_stripe_draw(g->vs);
		screen_pos = point_right(screen_pos);
		sprite_x += inc;
		--num_of_pixels;
	}
}

int	key_press(int keycode, t_game *g)
{
	static double	xx = 168;
	static double	yy = 168;
	static double	pixels = 64;

	if (KEY_W == keycode)
	{
		xx -= (pixels / 2);
		yy -= (pixels / 2);
		pixels *= 2;
	}
	else if (KEY_S == keycode)
	{
		pixels /= 2;
		xx += (pixels / 2);
		yy += (pixels / 2);
	}
	game_draw(g);
	draw_adjusted_sprite(g, (t_point){xx, yy}, pixels);
	screen_put_screen_to_window(g->screen);
	return (0);
}

t_error_code	game_start(t_game *g)
{
	game_draw(g);
	draw_adjusted_sprite(g, (t_point){168, 168}, 64);
	screen_put_screen_to_window(g->screen);
	mlx_key_hook(g->screen->win, key_press, g);
	mlx_loop(g->mlx);
	return (SUCCESS);
}
