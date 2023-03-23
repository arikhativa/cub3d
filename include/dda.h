/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:10:14 by anonymous         #+#    #+#             */
/*   Updated: 2023/03/23 11:22:34 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_H
# define DDA_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# include "radian.h"
# include "libft.h"
# include "angle.h"
# include "fpoint.h"
# include "point.h"
# include "ray.h"
# include "collision.h"

void	dda(char **map, t_player *p, t_ray	*ray_data, t_fpoint *collision);
void	dda_set_incrementor(t_ray *ray_data, double alpha);
void	dda_set_ray_data(t_ray *ray_data, double alpha, t_player *player);

#endif