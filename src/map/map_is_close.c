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

t_bool	rec_is_bad_map(char **map, t_point pos)
{
	t_bool	stt;

	if (!map_is_valid_pos(map, pos) || map_is_space(map, pos))
		return (TRUE);
	if (map_is_old_pos(map, pos) || map_is_wall(map, pos))
		return (FALSE);
	mark_pos(map, pos);
	stt = rec_is_bad_map(map, point_up(pos));
	stt += rec_is_bad_map(map, point_down(pos));
	stt += rec_is_bad_map(map, point_left(pos));
	stt += rec_is_bad_map(map, point_right(pos));
	return (!!stt);
}

t_error_code	map_is_closed(t_map *m, t_bool *is_closed)
{
	t_point			pos;
	char			**tmp_map;
	t_error_code	err;

	err = tab_dup(&tmp_map, m->map);
	if (err != SUCCESS)
		return (err);
	pos = fpoint_to_point(m->p->pos);
	tmp_map[pos.y][pos.x] = EMPTY_SPACE_CHAR;
	*is_closed = !rec_is_bad_map(tmp_map, pos);
	tab_deep_destroy(&tmp_map);
	return (SUCCESS);
}
