/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:10:14 by anonymous         #+#    #+#             */
/*   Updated: 2023/02/28 12:39:38 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANGLE_H
# define ANGLE_H

# include <math.h>

# include "player.h"
# include "direction.h"

typedef struct s_angle
{
	double	radians;
	double	min_in_range;
	double	max_in_range;
}				t_angle;

void	starting_angle(t_angle *angle, t_player *player);
void	adjust_angle(double angle);
void	set_angle_range(t_angle	*range);

#endif
