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

t_plane	*plane_mngr_get_plane(t_plane_mngr *pm, t_plane_type type)
{
	return (pm->planes[type]);
}

void	plane_mngr_print(t_plane_mngr *pm)
{
	int	i;

	if (!pm)
		return ;
	i = 0;
	while (i < PLANES_IN_MAP)
	{
		plane_print(pm->planes[i]);
		i++;
	}
}

t_bool	plane_mngr_is_loaded(t_plane_mngr *pm, t_plane_type t)
{
	if (PLANE_TYPE_ERROR != t)
		return (plane_is_loaded(pm->planes[t]));
	return (FALSE);
}
