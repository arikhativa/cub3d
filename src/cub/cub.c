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

static t_error_code	cub_is_sprite_valid(char *line, char *prefix)
{
	int	len;

	len = ft_strlen(prefix);
	if (ft_strncmp(line, prefix, len))
		return (EXT_BAD_PREFIX);
	line += len;
	if (!file_mngr_is_file(line))
		return (EXT_BAD_SPRITE_FILE);
	return (SUCCESS);
}

static t_error_code	cub_validate_plane(char *line, char *prefix)
{
	int	len;
	int	stt;
	int	n;
	int	num_in_line;

	len = ft_strlen(prefix);
	if (ft_strncmp(line, prefix, len))
		return (EXT_BAD_PREFIX);
	line += len;
	num_in_line = 0;
	while (*line)
	{
		stt = atoi_overflow(line, &n);
		if (n > 255 || n < 0 || stt == ERROR)
			return (EXT_BAD_COLOR);
		++num_in_line;
		while (ft_isdigit(*line))
			++line;
		if (*line == '\0' && num_in_line == 3)
			return (SUCCESS);
		if (*line != ',')
			return (EXT_BAD_CHAR_IN_PLANE);
		++line;
	}
	return (EXT_MISSING_PLANE_COLOR);
}

t_error_code	cub_validate_line(char *line)
{
	t_line_type	type;

	type = cub_get_line_type(line);
	if (LINE_TYPE_EMPTY == type)
		return (SUCCESS);
	else if (LINE_TYPE_MAP == type)
		return (SUCCESS);
	else if (LINE_TYPE_NORTH == type)
		return (cub_is_sprite_valid(line, NORTH_STR));
	else if (LINE_TYPE_SOUTH == type)
		return (cub_is_sprite_valid(line, SOUTH_STR));
	else if (LINE_TYPE_WEST == type)
		return (cub_is_sprite_valid(line, WEST_STR));
	else if (LINE_TYPE_EAST == type)
		return (cub_is_sprite_valid(line, EAST_STR));
	else if (LINE_TYPE_FLOOR == type)
		return (cub_validate_plane(line, FLOOR_STR));
	else if (LINE_TYPE_CEILING == type)
		return (cub_validate_plane(line, CEILING_STR));
	return (EXT_INVALID_LINE);
}

t_error_code	cub_validate_by_line(char **file)
{
	int				i;
	t_error_code	stt;

	i = 0;
	stt = SUCCESS;
	while (file[i] && SUCCESS == stt)
	{
		stt = cub_validate_line(file[i]);
		++i;
	}
	return (stt);
}
