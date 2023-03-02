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

int	map_get_map_index(char **file)
{
	t_line_type	type;
	int			i;

	i = 0;
	while (file[i])
	{
		type = cub_get_line_type(file[i]);
		if (LINE_TYPE_MAP == type)
			return (i);
		++i;
	}
	return (ERROR);
}

// TODO: fix this
		// while (x < m->size.x)
		// {
		// 	if (m->map[i][x] == '\0')
		// 		m->map[i][x] = ' ';
		// 	++x;
		// }
t_error_code	map_load_map(t_map *m)
{
	int		file_index;
	int		i;

	file_index = map_get_map_index(m->file);
	if (ERROR == file_index)
		return (ERROR);
	i = 0;
	while (m->file[file_index + i])
	{
		ft_memcpy(m->map[i], m->file[file_index + i], \
			ft_strlen(m->file[file_index + i]));
		++i;
	}
	return (SUCCESS);
}

t_error_code	map_load_sprite(t_map *m, char *line, char *prefix)
{
	t_direction	d;

	d = cub_get_direction(prefix);
	if (DIR_INVALID != d)
		return (sprite_mngr_load_sprite(m->sm, d, line + ft_strlen(prefix)));
	return (ERROR);
}

// TODO check for duplicate planes!
t_error_code	map_load_plane(t_map *m, char *line, char *prefix)
{
	t_plane_type	type;
	t_rgb			rgb;

	rgb = cub_get_rgb(line);
	type = cub_get_plane_type(prefix);
	if (PLANE_TYPE_ERROR == type)
		return (ERROR);
	plane_mngr_init(m->pm, type, rgb);
	return (SUCCESS);
}
