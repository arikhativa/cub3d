/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:11:45 by ycarro            #+#    #+#             */
/*   Updated: 2023/02/28 12:23:58 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "angle.h"

void	angle_starting(t_angle *angle, t_player *player)
{
	if (player->dir == NORTH)
		angle->radians = ((3.0 / 2.0) * M_PI);
	if (player->dir == SOUTH)
		angle->radians = (2.0 * M_PI);
	if (player->dir == EAST)
		angle->radians = ((1.0 / 2.0) * M_PI);
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
