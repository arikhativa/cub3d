/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/15 13:55:57 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane_mngr.h"

static t_error_code	create_planes(t_plane_mngr *pm)
{
	t_error_code	err;
	int				i;

	if (!pm)
		return (ERROR);
	i = 0;
	while (i < PLANES_IN_MAP)
	{
		err = plane_create(&(pm->planes[i]));
		if (SUCCESS != err)
			return (err);
		i++;
	}
	return (SUCCESS);
}

t_error_code	plane_mngr_create(t_plane_mngr **ret)
{
	t_error_code	err;
	t_plane_mngr	*tmp;

	if (!ret)
		return (ERROR);
	tmp = (t_plane_mngr *)ft_calloc(1, sizeof(t_plane_mngr));
	if (!tmp)
		return (ALLOCATION_ERROR);
	err = create_planes(tmp);
	if (SUCCESS != err)
	{
		plane_mngr_destroy(&tmp);
		return (err);
	}
	*ret = tmp;
	return (SUCCESS);
}

static void	destroy_planes(t_plane_mngr *pm)
{
	int	i;

	if (!pm)
		return ;
	i = 0;
	while (i < PLANES_IN_MAP)
	{
		plane_destroy(&(pm->planes[i]));
		i++;
	}
}

void	plane_mngr_destroy(t_plane_mngr **obj)
{
	t_plane_mngr	*tmp;

	if (!obj || !*obj)
		return ;
	tmp = *obj;
	if (tmp->planes)
		destroy_planes(tmp);
	ft_bzero(tmp, sizeof(t_plane_mngr));
	free(tmp);
	*obj = NULL;
}

void	plane_mngr_init(t_plane_mngr *pm, t_plane_type type, t_rgb color)
{
	if (!pm)
		return ;
	plane_init(pm->planes[type], color);
}
