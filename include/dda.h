/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:48:30 by ycarro            #+#    #+#             */
/*   Updated: 2023/02/23 17:10:26 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_H
# define DDA_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# include "libft.h"
# include "angle.h"
# include "point.h"
# include "player.h"

typedef struct s_ray
{
	t_point	x_pos;
	t_point	y_pos;
	double	slope;
	double	intercept;
	double	*incrementor;
	t_angle	to_cast;
}				t_ray;

void	dda(char **map, t_player *p, t_ray	*ray_data, t_point *collision);
void	set_incrementor(t_ray *ray_data, double alpha);
void	get_ray_data(t_ray *ray_data, double alpha, t_player *player);

#endif