/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:57:17 by ycarro            #+#    #+#             */
/*   Updated: 2023/02/27 15:39:02 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANGLE_H
# define ANGLE_H

# include <math.h>

# include "player.h"
# include "direction.h"

# define ANGLE_NORTH			(3.0 / 2.0) * M_PI
# define ANGLE_WEST				M_PI
# define ANGLE_EAST				(1.0 / 2.0) * M_PI
# define ANGLE_SOUTH			2.0 * M_PI
# define ANGLE_MAX				2.0 * M_PI	
# define ANGLE_HALF_QUARTER		(1.0 / 4.0) * M_PI

typedef struct s_angle
{
	double	radians;
	double	min_in_range;
	double	max_in_range;
}				t_angle;

void	angle_starting(t_angle *angle, t_player *player);
void	angle_adjust(double angle);
void	angle_set_range(t_angle	*range);

#endif