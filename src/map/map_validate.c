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

t_error_code	map_validate(char **file)
{
	t_error_code	err;

	err = cub_validate_by_line(file);
	if (SUCCESS != err)
		return (err);
	err = cub_validate_map_at_bottom(file);
	return (err);
}

t_error_code	map_post_load_validation(t_map *m)
{
	t_bool			is_closed;
	t_error_code	err;

	is_closed = FALSE;
	err = map_is_closed(m, &is_closed);
	if (SUCCESS != err)
		return (err);
	if (!is_closed)
		return (EXT_MAP_OPEN);
	return (SUCCESS);
}
