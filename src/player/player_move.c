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

void	player_move_forward(t_player *p, char **map)
{
	player_move(p, map, p->dir);
}

void	player_move_backward(t_player *p, char **map)
{
	double		sloop;

	sloop = p->dir + radian(180);
	player_move(p, map, sloop);
}

void	player_move_left(t_player *p, char **map)
{
	double		sloop;

	sloop = p->dir + radian(90);
	player_move(p, map, sloop);
}

void	player_move_right(t_player *p, char **map)
{
	double		sloop;

	sloop = p->dir - radian(90);
	player_move(p, map, sloop);
}
