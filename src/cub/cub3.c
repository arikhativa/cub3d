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
