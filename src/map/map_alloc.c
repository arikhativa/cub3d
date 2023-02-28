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

void	map_get_size(t_map *m)
{
	int	i;
	int	map_index;
	int	len_x;
	int	tmp_len;

	i = 0;
	len_x = 0;
	map_index = map_get_map_index(m->file);
	while (m->file[map_index + i])
	{
		tmp_len = ft_strlen(m->file[map_index + i]);
		if (len_x < tmp_len)
			len_x = tmp_len;
		++i;
	}
	m->size = point_init(len_x + 1, i);
}

static t_error_code	map_init_lines(t_map *m)
{
	int	i;

	i = 0;
	while (i < m->size.y)
	{
		m->map[i] = ft_calloc(1, m->size.x);
		if (!m->map[i])
			return (ALLOCATION_ERROR);
		++i;
	}
	return (SUCCESS);
}

t_error_code	map_alloc_map(t_map *m)
{
	t_error_code	err;

	map_get_size(m);
	err = tab_create(&m->map, m->size.y);
	if (SUCCESS == err)
		map_init_lines(m);
	return (err);
}
