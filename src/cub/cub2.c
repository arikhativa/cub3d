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

static t_bool	is_line_map(char *line)
{
	int		i;
	char	*p;

	i = 0;
	while (line[i])
	{
		p = ft_strchr(VALID_MAP_CHARS, line[i]);
		if (!p)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

t_line_type	cub_get_line_type(char *line)
{
	if (!ft_strcmp(line, EMPTY_STR))
		return (LINE_TYPE_EMPTY);
	else if (!ft_strncmp(line, NORTH_STR, ft_strlen(NORTH_STR)))
		return (LINE_TYPE_NORTH);
	else if (!ft_strncmp(line, SOUTH_STR, ft_strlen(SOUTH_STR)))
		return (LINE_TYPE_SOUTH);
	else if (!ft_strncmp(line, WEST_STR, ft_strlen(WEST_STR)))
		return (LINE_TYPE_WEST);
	else if (!ft_strncmp(line, EAST_STR, ft_strlen(EAST_STR)))
		return (LINE_TYPE_EAST);
	else if (!ft_strncmp(line, FLOOR_STR, ft_strlen(FLOOR_STR)))
		return (LINE_TYPE_FLOOR);
	else if (!ft_strncmp(line, CEILING_STR, ft_strlen(CEILING_STR)))
		return (LINE_TYPE_CEILING);
	else if (is_line_map(line))
		return (LINE_TYPE_MAP);
	else
		return (LINE_TYPE_INVALID);
}
