/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:57:33 by ycarro            #+#    #+#             */
/*   Updated: 2023/04/11 16:53:20 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_H
# define COLLISION_H

# include "macro.h"
# include "ray.h"

typedef enum e_collision
{
	NO_COLLISION = -1,
	X_COLLISION = 0,
	Y_COLLISION = 1,
}	t_collision;

typedef struct s_collinfo
{
	t_fpoint	collision;
	t_point		collider;
	int			axis;

}				t_collinfo;

int				is_collides(t_ray *ray_data, char **map, t_collinfo *collinfo);
t_collision		check_in_range(t_ray *ray_data, char **map, \
				t_collinfo *collinfo);
void			get_map_index(t_ray *ray_data, t_fpoint pos, \
				int incrementor, int *point);

#endif