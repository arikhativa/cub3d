/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:11:45 by ycarro            #+#    #+#             */
/*   Updated: 2023/02/27 15:31:16 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "angle.h"

void	angle_starting(t_angle *angle, t_player *player)
{
	if (player->dir == NORTH)
		angle->radians = ANGLE_NORTH;
	if (player->dir == SOUTH)
		angle->radians = ANGLE_SOUTH;
	if (player->dir == EAST)
		angle->radians = ANGLE_EAST;
	if (player->dir == WEST)
		angle->radians = ANGLE_WEST;
}

void	angle_adjust(double angle)
{
	if (angle > ANGLE_MAX)
		angle -= ANGLE_MAX;
	if (angle < 0)
		angle += ANGLE_MAX;
}

void	angle_set_range(t_angle	*range)
{
	range->min_in_range = range->radians - ANGLE_HALF_QUARTER;
	range->max_in_range = range->radians + ANGLE_HALF_QUARTER;
	angle_adjust(range->min_in_range);
	angle_adjust(range->max_in_range);
}
