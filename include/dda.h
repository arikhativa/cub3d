/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:10:14 by anonymous         #+#    #+#             */
/*   Updated: 2023/04/18 13:46:24 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_H
# define DDA_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# include "radian.h"
# include "libft.h"
# include "fpoint.h"
# include "ray.h"
# include "collision.h"

void	dda(char **map, t_fpoint start, t_ray *ray_data, t_collinfo *collinfo);
t_bool	dda_is_wall_near(char **map, t_fpoint start, double dir);

#endif