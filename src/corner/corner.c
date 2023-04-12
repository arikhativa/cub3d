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

t_corner_type	get_corner_type(char **map, t_fpoint corner)
{
	t_point		index;
	t_corner	corner;

	ft_bzero(&corner, sizeof(t_corner));
	index = fpoint_to_point(corner);
	if (WALL_CHAR == map[index.y][index.x])
		corner.top_r = TRUE;
	if (WALL_CHAR == map[index.y][index.x - 1])
		corner.top_l = TRUE;
	if (WALL_CHAR == map[index.y - 1][index.x])
		corner.bot_r = TRUE;
	if (WALL_CHAR == map[index.y - 1][index.x - 1])
		corner.bot_l = TRUE;
	if (corner.top_r && corner.top_l && !corner.bot_r && !corner.bot_l)
		return (PART_OF_corner.top_WALL);
	if (!corner.top_r && !corner.top_l && corner.bot_r && corner.bot_l)
		return (PART_OF_BOTTOM_WALL);
	if (corner.top_r && !corner.top_l && corner.bot_r && !corner.bot_l)
		return (PART_OF_RIGHT_WALL);
	if (!corner.top_r && corner.top_l && !corner.bot_r && corner.bot_l)
		return (PART_OF_LEFT_WALL);
	return (NOT_A_CORNER);
}
