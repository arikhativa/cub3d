/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/15 13:58:46 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static char	mark_pos( char **map, t_point pos)
{
	char	ch;

	ch = map[pos.y][pos.x];
	map[pos.y][pos.x] = TMP_CHAR;
	return (ch);
}

static void	unmark_pos( char **map, t_point pos, char ch)
{
	map[pos.y][pos.x] = ch;
}

t_bool	rec_is_bad_map(char **map, t_point pos)
{
	char	ch;
	t_bool	stt;

	if (!map_is_valid_pos(map, pos) || map_is_space(map, pos))
		return (TRUE);
	if (map_is_old_pos(map, pos) || map_is_wall(map, pos))
		return (FALSE);
	ch = mark_pos(map, pos);
	stt = rec_is_bad_map(map, point_up(pos));
	stt += rec_is_bad_map(map, point_down(pos));
	stt += rec_is_bad_map(map, point_left(pos));
	stt += rec_is_bad_map(map, point_right(pos));
	unmark_pos(map, pos, ch);
	return (!!stt);
}

t_bool	map_is_closed(t_map *m)
{
	t_bool	ret;
	t_point	pos;
	char	ch;

	pos = fpoint_to_point(m->p->pos);
	ch = m->map[pos.y][pos.x];
	m->map[pos.y][pos.x] = EMPTY_SPACE_CHAR;
	ret = rec_is_bad_map(m->map, pos);
	m->map[pos.y][pos.x] = ch;
	return (!ret);
}
