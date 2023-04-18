/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:46:30 by yrabby            #+#    #+#             */
/*   Updated: 2023/04/18 14:08:20 by yrabby           ###   ########.fr       */
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

t_bool	can_player_move(t_player *p, char **map, double sloop)
{
	if (radian_is_north_west(sloop))
		return (!dda_is_wall_near(map, p->pos, radian(90)) || \
			!dda_is_wall_near(map, p->pos, radian(180)));
	if (radian_is_north_east(sloop))
		return (!dda_is_wall_near(map, p->pos, radian(90)) || \
			!dda_is_wall_near(map, p->pos, radian(0)));
	if (radian_is_south_east(sloop))
		return (!dda_is_wall_near(map, p->pos, radian(270)) || \
			!dda_is_wall_near(map, p->pos, radian(0)));
	if (radian_is_south_west(sloop))
		return (!dda_is_wall_near(map, p->pos, radian(270)) || \
			!dda_is_wall_near(map, p->pos, radian(180)));
	return (TRUE);
}

void	player_move(t_player *p, char **map, double sloop)
{
	t_fpoint	next_p;

	if (!can_player_move(p, map, sloop))
		return ;
	next_p = get_next_fpoint(p->pos, sloop);
	if (!is_wall(next_p, map))
		p->pos = next_p;
}
