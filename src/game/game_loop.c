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

void	draw_line_y(t_game *g, t_point screen_pos, double sprite_x, double num_of_pixels)
{
	double		sprite_y = 0;
	t_sprite	*sprite = g->map->sm->sprites[0];
	double inc = sprite->size.y / num_of_pixels;
	int color = 0;
	
	while (num_of_pixels)
	{
		color = sprite_get_pixel_color(sprite, (t_point){sprite_x, sprite_y});
		screen_color_pixel(g->screen, screen_pos, color);
		sprite_y += inc;
		screen_pos = point_down(screen_pos);
		--num_of_pixels;
	}
}

void	draw_adjusted_sprite(t_game *g, t_point screen_pos, double num_of_pixels)
{
	t_sprite	*sprite = g->map->sm->sprites[0];
	double	sprite_x = 0;
	double inc = sprite->size.x / num_of_pixels;
	double og_num_of_pixels = num_of_pixels;

	while (num_of_pixels)
	{
		draw_line_y(g, screen_pos, sprite_x, og_num_of_pixels);
		screen_pos = point_right(screen_pos);
		sprite_x += inc;
		--num_of_pixels;
	}
}

	static	double xx = 168;
	static	double yy = 168;
	static	double pixels = 64;

int	key_press(int keycode, t_game *g)
{
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
	draw_adjusted_sprite(g, (t_point){xx, yy}, pixels);
	screen_put_screen_to_window(g->screen);
	mlx_key_hook(g->screen->win, key_press, g);
	mlx_loop(g->mlx);
	return (SUCCESS);
}
