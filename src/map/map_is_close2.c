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

t_bool	map_is_valid_pos(char **m, t_point pos)
{
	return (m && m[pos.y] && m[pos.y][pos.x]);
}

t_bool	map_is_space(char **m, t_point pos)
{
	return (SPACE_CHAR == m[pos.y][pos.x]);
}

t_bool	map_is_old_pos(char **m, t_point pos)
{
	return (TMP_CHAR == m[pos.y][pos.x]);
}

t_bool	map_is_wall(char **m, t_point pos)
{
	return (WALL_CHAR == m[pos.y][pos.x]);
}
