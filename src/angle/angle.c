/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:11:45 by ycarro            #+#    #+#             */
/*   Updated: 2023/03/23 07:12:40 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "angle.h"

void	angle_starting(t_angle *angle, t_player *player)
{
	if (player->dir == NORTH)
		angle->radians = M_PI / 2);
	if (player->dir == SOUTH)
		angle->radians = (1.5 * M_PI);
	if (player->dir == EAST)
		angle->radians = 0;
	if (player->dir == WEST)
		angle->radians = M_PI;
}

void	angle_adjust(double angle)
{
	if (angle > (2.0 * M_PI))
		angle -= (2.0 * M_PI);
	if (angle < 0)
		angle += (2.0 * M_PI);
}

void	angle_set_range(t_angle	*range)
{
	range->min_in_range = range->radians - ((1.0 / 4.0) * M_PI);
	range->max_in_range = range->radians + ((1.0 / 4.0) * M_PI);
	angle_adjust(range->min_in_range);
	angle_adjust(range->max_in_range);
}
