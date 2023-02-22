/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:48:30 by ycarro            #+#    #+#             */
/*   Updated: 2023/02/22 15:03:29 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_H
# define DDA_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# include "error_code.h"
# include "libft.h"
# include "angle.h"

typedef struct s_ray
{
	double	slope;
	double	intercept;
	double	incrementor;
}				t_ray;

t_point	dda(char **map, t_player *p, t_angle *ray_to_cast);

#endif