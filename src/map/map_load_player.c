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

static t_error_code	map_load_player_by_line(t_map *m, int y)
{
	char		*line;
	int			x;
	t_fpoint	pos;
	t_direction	dir;

	x = 0;
	line = m->map[y];
	while (line[x])
	{
		if (ft_strchr(PLAYER_DIR_STR, line[x]))
		{
			if (player_is_loaded(m->p))
				return (EXT_DUPLICATE_SETTING);
			pos = fpoint_init(x, y);
			dir = direction_char_to_dir(line[x]);
			player_init(m->p, pos, dir);
		}
		++x;
	}
	return (SUCCESS);
}

t_error_code	map_load_player(t_map *m)
{
	t_error_code	err;
	int				y;

	y = 0;
	err = SUCCESS;
	while (y < m->size.y)
	{
		err = map_load_player_by_line(m, y);
		if (err != SUCCESS)
			return (err);
		++y;
	}
	if (SUCCESS == err && !player_is_loaded(m->p))
		return (EXT_MISSING_PLAYER);
	return (err);
}
