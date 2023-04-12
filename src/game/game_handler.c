/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/04/12 11:18:51 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	game_handler_vision(t_game *g, int key)
{
	t_player	*p;

	p = g->map->p;
	if (key == KEY_LEFT)
		player_rotate_left(p);
	if (key == KEY_RIGHT)
		player_rotate_right(p);
}

void	game_handler_movement(t_game *g, int key)
{
	t_player	*p;

	p = g->map->p;
	if (key == KEY_W)
		player_move_forward(p, g->map->map);
	if (key == KEY_S)
		player_move_backward(p, g->map->map);
	if (key == KEY_A)
		player_move_left(p, g->map->map);
	if (key == KEY_D)
		player_move_right(p, g->map->map);
}

void	game_handler_exit(t_game *g)
{
	game_destroy(&g);
	exit(0);
}

int	game_handler_x_button(t_game *g)
{
	game_handler_exit(g);
	return (0);
}
