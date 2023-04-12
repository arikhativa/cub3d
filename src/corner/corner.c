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

#include "corner.h"

t_corner	corner_init(char **map, t_fpoint pos)
{
	t_point		index;
	t_corner	corner;

	ft_bzero(&corner, sizeof(t_corner));
	index = fpoint_to_point(pos);
	if (WALL_CHAR == map[index.y][index.x])
		corner.top_r = TRUE;
	if (WALL_CHAR == map[index.y][index.x - 1])
		corner.top_l = TRUE;
	if (WALL_CHAR == map[index.y - 1][index.x])
		corner.bot_r = TRUE;
	if (WALL_CHAR == map[index.y - 1][index.x - 1])
		corner.bot_l = TRUE;
	return (corner);
}

t_corner_type	get_corner_type(char **map, t_fpoint pos)
{
	t_corner	corner;

	corner = corner_init(map, pos);
	if (corner.top_r && corner.top_l && !corner.bot_r && !corner.bot_l)
		return (PART_OF_TOP_WALL);
	if (!corner.top_r && !corner.top_l && corner.bot_r && corner.bot_l)
		return (PART_OF_BOTTOM_WALL);
	if (corner.top_r && !corner.top_l && corner.bot_r && !corner.bot_l)
		return (PART_OF_RIGHT_WALL);
	if (!corner.top_r && corner.top_l && !corner.bot_r && corner.bot_l)
		return (PART_OF_LEFT_WALL);
	return (NOT_A_CORNER);
}

t_point	get_index_by_corner_type(char **map, t_fpoint pos)
{
	t_corner		corner;
	t_point			index;

	corner = corner_init(map, pos);
	index = fpoint_to_point(pos);
	if (corner.bot_r)
		index.y--;
	else if (corner.bot_l)
	{
		index.x--;
		index.y--;
	}
	else if (corner.top_l)
		index.x--;
	return (index);
}
