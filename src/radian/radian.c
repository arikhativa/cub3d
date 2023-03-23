/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radian.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/03/23 12:14:12 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "radian.h"

double	radian(double degree)
{
	while (360 <= degree)
		degree -= 360;
	while (0 > degree)
		degree += 360;
	return (degree * (M_PI / 180));
}

double		radian_set_boundaries(double radian)
{
	double	max;

	max = 2 * M_PI;
	while (max <= radian)
		radian -= max;
	while (0 > radian)
		radian += max;
	return (radian);
}

t_direction	radian_get_direction(double radian)
{
	if (radian_is_north(radian))
		return (NORTH);
	else if (radian_is_east(radian))
		return (EAST);
	else if (radian_is_south(radian))
		return (SOUTH);
	else if (radian_is_west(radian))
		return (WEST);
	else if (radian_is_north_east(radian))
		return (NE);
	else if (radian_is_north_west(radian))
		return (NW);
	else if (radian_is_south_east(radian))
		return (SE);
	else if (radian_is_south_west(radian))
		return (SW);
	return (DIR_INVALID);
}
