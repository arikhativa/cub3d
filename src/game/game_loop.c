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

int	key_press(int keycode, t_game *g)
{
	if (mlx_keys_is_vision(keycode))
		game_handler_vision(g, keycode);
	if (mlx_keys_is_movement(keycode))
		game_handler_movement(g, keycode);
	if (mlx_keys_is_exit(keycode))
		game_handler_exit(g, keycode);
	game_draw(g);
	return (0);
}

t_error_code	game_start(t_game *g)
{
	game_draw(g);
	mlx_key_hook(g->screen->win, key_press, g);
	mlx_loop(g->mlx);
	return (SUCCESS);
}
