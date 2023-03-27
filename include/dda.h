/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:10:14 by anonymous         #+#    #+#             */
/*   Updated: 2023/03/24 17:01:53 by ycarro           ###   ########.fr       */
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
# include "ray.h"
# include "collision.h"

void	dda(char **map, t_player *p, t_ray	*ray_data, t_fpoint *collision);

#endif