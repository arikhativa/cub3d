/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/03/23 11:11:11 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CASTER_H
# define RAY_CASTER_H

# include <stdlib.h>

# include "radian.h"
# include "vertical_stripe.h"
# include "dda.h"
# include "libft.h"
# include "map.h"
# include "corner.h"
# include "error_code.h"

typedef struct s_ray_caster
{
	t_ray				ray;
	int					num_of_rays;
	double				direction;
	t_fpoint			start;
	t_map				*map;
	t_vertical_stripe	*vs;
}				t_ray_caster;

t_error_code	ray_caster_create(t_ray_caster **ret);
void			ray_caster_init(t_ray_caster *rc, int num_of_rays, \
	t_map *map, t_vertical_stripe *vs);
void			ray_caster_set(t_ray_caster *rc, t_fpoint start, \
	double direction);
void			ray_caster_destroy(t_ray_caster **obj);
void			ray_caster_cast(t_ray_caster *rc);

#endif