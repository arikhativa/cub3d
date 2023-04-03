/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/03/23 11:20:07 by yrabby           ###   ########.fr       */
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

void	ray_caster_init(t_ray_caster *rc, int num_of_rays, t_map *map, \
	t_vertical_stripe *vs)
{
	if (!rc)
		return ;
	rc->map = map;
	rc->num_of_rays = num_of_rays;
	rc->vs = vs;
}

void	ray_caster_set(t_ray_caster *rc, t_fpoint start, double direction)
{
	if (!rc)
		return ;
	rc->start = start;
	rc->direction = direction;
}
