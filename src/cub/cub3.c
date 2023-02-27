/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/15 13:55:57 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_error_code	cub_validate_map_at_bottom(char **file)
{
	int			i;
	t_bool		is_found_map;
	t_line_type	type;

	i = 0;
	is_found_map = FALSE;
	while (file[i])
	{
		type = cub_get_line_type(file[i]);
		if (LINE_TYPE_MAP != type && TRUE == is_found_map)
			return (EXT_MAP_NOT_AT_BOTTOM);
		if (LINE_TYPE_MAP == type)
			is_found_map = TRUE;
		++i;
	}
	return (SUCCESS);
}

t_direction	cub_get_direction(char *prefix)
{
	if (!prefix)
		return (DIR_INVALID);
	else if (!ft_strcmp(NORTH_STR, prefix))
		return (NORTH);
	else if (!ft_strcmp(SOUTH_STR, prefix))
		return (SOUTH);
	else if (!ft_strcmp(EAST_STR, prefix))
		return (EAST);
	else if (!ft_strcmp(WEST_STR, prefix))
		return (WEST);
	return (DIR_INVALID);
}

t_plane_type	cub_get_plane_type(char *prefix)
{
	if (!prefix)
		return (PLANE_TYPE_ERROR);
	else if (!ft_strcmp(FLOOR_STR, prefix))
		return (PLANE_TYPE_FLOOR);
	else if (!ft_strcmp(CEILING_STR, prefix))
		return (PLANE_TYPE_CEILING);
	return (PLANE_TYPE_ERROR);
}
