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

t_error_code	map_load_line(t_map *m, char *line)
{
	t_line_type	type;

	type = cub_get_line_type(line);
	if (LINE_TYPE_EMPTY == type)
		return (SUCCESS);
	else if (LINE_TYPE_MAP == type)
		return (STOP);
	else if (LINE_TYPE_NORTH == type)
		return (map_load_sprite(m, line, NORTH_STR));
	else if (LINE_TYPE_SOUTH == type)
		return (map_load_sprite(m, line, SOUTH_STR));
	else if (LINE_TYPE_WEST == type)
		return (map_load_sprite(m, line, WEST_STR));
	else if (LINE_TYPE_EAST == type)
		return (map_load_sprite(m, line, EAST_STR));
	else if (LINE_TYPE_FLOOR == type)
		return (map_load_plane(m, line, FLOOR_STR));
	else if (LINE_TYPE_CEILING == type)
		return (map_load_plane(m, line, CEILING_STR));
	return (EXT_INVALID_FILE);
}

t_error_code	map_load_settings(t_map *m)
{
	int				i;
	t_error_code	err;

	i = 0;
	err = SUCCESS;
	while (m->file[i] && SUCCESS == err)
	{
		err = map_load_line(m, m->file[i]);
		++i;
	}
	if (STOP == err)
		return (SUCCESS);
	return (err);
}

t_error_code	map_load(t_map *m)
{
	t_error_code	err;

	err = map_load_settings(m);
	if (SUCCESS != err)
		return (err);
	err = map_alloc_map(m);
	if (SUCCESS != err)
		return (err);
	err = map_load_map(m);
	return (err);
}
