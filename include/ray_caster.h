/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/03/22 09:06:32 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CASTER_H
# define RAY_CASTER_H

# include <stdlib.h>

# include "dda.h"
# include "libft.h"
# include "map.h"
# include "error_code.h"

typedef struct s_ray_caster
{
	int			num_of_rays;
	t_player	*p;
	t_map		*map;
}				t_ray_caster;

t_error_code	ray_caster_create(t_ray_caster **ret);
void			ray_caster_init(t_ray_caster *rc, int num_of_rays, t_player *p, t_map *map);
void			ray_caster_destroy(t_ray_caster **obj);
t_error_code	ray_caster_cast(t_ray_caster *rc);

#endif
