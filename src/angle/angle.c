/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:11:45 by ycarro            #+#    #+#             */
/*   Updated: 2023/02/22 18:03:41 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "angle.h"

void	starting_angle(t_angle *angle, t_player *player)
{
	if (player->dir == NORTH)
		angle->radians = (3.0 / 2.0) * M_PI;
	if (player->dir == SOUTH)
		angle->radians = (1.0 / 2.0) * M_PI;
	if (player->dir == EAST)
		angle->radians = 2.0 * M_PI;
	if (player->dir == WEST)
		angle->radians = M_PI;
}

void	adjust_angle(double angle)
{
	if (angle > (2.0 * M_PI))
		angle -= (2.0 * M_PI);
	if (angle < 0)
		angle += (2.0 * M_PI);
}

void	set_angle_range(t_angle	*range)
{
	range->min_in_range = range->radians - ((1.0 / 4.0) * M_PI);
	range->max_in_range = range->radians + ((1.0 / 4.0) * M_PI);
	adjust_angle(range->min_in_range);
	adjust_angle(range->max_in_range);
}
