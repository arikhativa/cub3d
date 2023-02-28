/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:48:30 by ycarro            #+#    #+#             */
/*   Updated: 2023/02/28 13:03:32 by anonymous        ###   ########.fr       */
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
# include "collision.h"

typedef struct s_ray
{
	t_point	x_pos;
	t_point	y_pos;
	double	slope;
	double	intercept;
	t_point	incrementor;
	t_angle	to_cast;
}				t_ray;

void	dda(char **map, t_player *p, t_ray	*ray_data, t_point *collision);
void	set_incrementor(t_ray *ray_data, double alpha);
void	get_ray_data(t_ray *ray_data, double alpha, t_player *player);
int		ray_differs_in_x(t_ray *ray_data);
void	ray_increment(t_ray	*ray_data);

#endif