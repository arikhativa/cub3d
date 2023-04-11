/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/04/11 23:19:19 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	key_press(int keycode, t_game *g)
{
	if (mlx_keys_is_vision(keycode))
		game_handler_vision(g, keycode);
	if (mlx_keys_is_movement(keycode))
		game_handler_movement(g, keycode);
	if (mlx_keys_is_exit(keycode))
		game_handler_exit(g);
	game_draw(g);
	return (SUCCESS);
}

static int	game_draw_handler(t_game *g)
{
	game_draw(g);
	return (SUCCESS);
}

t_error_code	game_start(t_game *g)
{
	mlx_key_hook(g->screen->win, key_press, g);
	mlx_expose_hook(g->screen->win, game_draw_handler, g);
	mlx_loop(g->mlx);
	return (SUCCESS);
}
