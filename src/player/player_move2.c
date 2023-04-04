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

static t_fpoint	get_next_fpoint(t_fpoint p, double sloop)
{
	p.y += sin(sloop) * MOVEMENT_SPEED;
	p.x += cos(sloop) * MOVEMENT_SPEED;
	return (p);
}

// TODO bad func! does not work
static t_bool	is_wall(t_fpoint p, char **map)
{
	int		x;
	int		y;

	x = (int)p.x;
	y = (int)p.y;
	return (map[y][x] == WALL_CHAR);
}

void	player_move(t_player *p, char **map, double sloop)
{
	t_fpoint	next_p;

	next_p = get_next_fpoint(p->pos, sloop);
	if (!is_wall(next_p, map))
		p->pos = next_p;
}
