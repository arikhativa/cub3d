/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:46:30 by yrabby            #+#    #+#             */
/*   Updated: 2023/04/19 11:35:54 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static t_fpoint	get_next_fpoint(t_fpoint p, double sloop)
{
	t_fpoint	tmp;

	tmp = fpoint_copy(p);
	p.y += sin(sloop) * MOVEMENT_SPEED;
	p.x += cos(sloop) * MOVEMENT_SPEED;
	if (0 == fmod(p.x, 1.0) || 0 == fmod(p.y, 1.0))
	{
		tmp.y += sin(sloop) * (MOVEMENT_SPEED - 0.05);
		tmp.x += cos(sloop) * (MOVEMENT_SPEED - 0.05);
		p = fpoint_copy(tmp);
	}
	return (p);
}

static t_bool	is_wall(t_fpoint p, char **map)
{
	t_point	pos;

	pos = fpoint_to_point(p);
	pos.x = (int)p.x;
    pos.y = (int)p.y;
	return (map[pos.y][pos.x] == WALL_CHAR);
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
