/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:46:30 by yrabby            #+#    #+#             */
/*   Updated: 2023/03/29 15:43:33 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static void	starting_angle(t_player *player)
{
	if (player->start_dir == NORTH)
		player->dir = radian(90);
	if (player->start_dir == SOUTH)
		player->dir = radian(-90);
	if (player->start_dir == EAST)
		player->dir = radian(0);
	if (player->start_dir == WEST)
		player->dir = radian(180);
}

void	player_init(t_player *obj, t_fpoint pos, t_direction dir)
{
	if (obj)
	{
		obj->pos.x = pos.x + 0.5;
		obj->pos.y = pos.y + 0.5;
		obj->start_dir = dir;
		starting_angle(obj);
	}
}
