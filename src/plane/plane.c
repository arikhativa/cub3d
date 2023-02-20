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

#include "plane.h"

t_error_code	plane_create(t_plane **ret)
{
	t_plane		*tmp;

	if (!ret)
		return (ERROR);
	tmp = (t_plane *)ft_calloc(1, sizeof(t_plane));
	if (!tmp)
		return (ALLOCATION_ERROR);
	*ret = tmp;
	return (SUCCESS);
}

void	plane_destroy(t_plane **obj)
{
	t_plane	*tmp;

	if (!obj || !*obj)
		return ;
	tmp = *obj;
	ft_bzero(tmp, sizeof(t_plane));
	free(tmp);
	*obj = NULL;
}

void	plane_init(t_plane *p, t_rgb color)
{
	if (!p)
		return ;
	p->color = color;
}
