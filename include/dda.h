/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:10:14 by anonymous         #+#    #+#             */
/*   Updated: 2023/02/28 13:58:10 by anonymous        ###   ########.fr       */
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
# include "ray.h"
# include "collision.h"

void	dda(char **map, t_player *p, t_ray	*ray_data, t_point *collision);
void	dda_set_incrementor(t_ray *ray_data, double alpha);
void	dda_set_ray_data(t_ray *ray_data, double alpha, t_player *player);

#endif