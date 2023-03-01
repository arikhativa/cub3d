/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:57:33 by ycarro            #+#    #+#             */
/*   Updated: 2023/02/28 13:58:32 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_H
# define COLLISION_H

# include "dda.h"
# include "macro.h"
# include "ray.h"

typedef enum e_collision
{
	NO_COLLISION = -1,
	X_COLLISION = 0,
	Y_COLLISION = 1,
}	t_collision;

t_bool	is_collides(t_ray *ray_data, char **map, t_point *collision);
t_collision		check_in_range(t_ray *ray_data, char **map);

#endif