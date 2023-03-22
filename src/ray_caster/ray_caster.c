/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/03/22 23:21:52 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_caster.h"

t_error_code	ray_caster_create(t_ray_caster **ret)
{
	t_ray_caster		*tmp;

	if (!ret)
		return (ERROR);
	tmp = (t_ray_caster *)ft_calloc(1, sizeof(t_ray_caster));
	if (!tmp)
		return (ALLOCATION_ERROR);
	*ret = tmp;
	return (SUCCESS);
}

void	ray_caster_destroy(t_ray_caster **obj)
{
	t_ray_caster	*tmp;

	if (!obj || !*obj)
		return ;
	tmp = *obj;
	ft_bzero(tmp, sizeof(t_ray_caster));
	free(tmp);
	*obj = NULL;
}

void	ray_caster_init(t_ray_caster *rc, int num_of_rays, t_player *p, \
	t_map *map)
{
	if (!rc)
		return ;
	rc->p = p;
	rc->map = map;
	rc->num_of_rays = num_of_rays;
}

t_error_code	ray_caster_cast(t_ray_caster *rc)
{
	t_ray		ray_data;
	t_fpoint	collision;

	angle_starting(&ray_data.to_cast, rc->p);
	dda(rc->map->map, rc->p, &ray_data, &collision);
	printf("coll point:\n");
	fpoint_print(collision);
	printf("\n");
	return (SUCCESS);
}
