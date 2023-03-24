/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:57:33 by ycarro            #+#    #+#             */
/*   Updated: 2023/03/24 17:19:08 by ycarro           ###   ########.fr       */
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

int				is_collides(t_ray *ray_data, char **map, t_fpoint *collision);
t_collision		check_in_range(t_ray *ray_data, char **map);

#endif