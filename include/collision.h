/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:57:33 by ycarro            #+#    #+#             */
/*   Updated: 2023/02/23 17:43:05 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_H
# define COLLISION_H

# include "dda.h"

typedef struct s_ray	t_ray;

int	it_collides(t_ray *ray_data, char **map, t_point *collision);
int	check_in_range(t_ray *ray_data, char **map);

#endif