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
	(void)g;
	(void)key;
}

void	game_handler_exit(t_game *g, int key)
{
	(void)g;
	(void)key;
}
