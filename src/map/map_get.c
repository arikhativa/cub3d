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

int	map_get_floor_color(t_map *m)
{
	int	color;

	color = rgb_to_int(&(m->pm->planes[PLANE_TYPE_FLOOR]->color));
	return (color);
}

int	map_get_celling_color(t_map *m)
{
	int	color;

	color = rgb_to_int(&(m->pm->planes[PLANE_TYPE_CEILING]->color));
	return (color);
}