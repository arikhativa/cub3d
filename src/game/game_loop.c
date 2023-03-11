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

void	draw_line_y(t_game *g, t_point screen_pos, int num_of_pixels)
{
	int	sprite_y = 0;
	t_sprite	*sprite = g->map->sm->sprites[0];
	int inc = sprite->size.y / num_of_pixels;
	int color = 0;
	
	while (num_of_pixels)
	{
		color = sprite_get_pixel_color(sprite, (t_point){0, sprite_y});
		screen_color_pixel(g->screen, screen_pos, color);
		sprite_y += inc;
		screen_pos = point_down(screen_pos);
		--num_of_pixels;
	}
}

int	key_press(int keycode, t_game *g)
{
	static	int xx = 200 - 32;
	static	int yy = 200 - 32;
	static	int pixels = 64;
	game_draw(g);
	if (KEY_W == keycode)
	{
		printf("W\n");
		draw_line_y(g, (t_point){xx, yy}, pixels);
	}
	else if (KEY_S == keycode)
		printf("S\n");
	(void)g;
	return (0);
}

t_error_code	game_start(t_game *g)
{
	game_draw(g);
	mlx_key_hook(g->screen->win, key_press, g);
	// mlx_put_image_to_window(g->mlx, g->screen->win, g->map->sm->sprites[0]->ref,200 - 32, 200 - 32);
	mlx_loop(g->mlx);
	return (SUCCESS);
}
