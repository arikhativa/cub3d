/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:57:17 by ycarro            #+#    #+#             */

/*   Updated: 2023/02/23 14:19:58 by ycarro           ###   ########.fr       */
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
