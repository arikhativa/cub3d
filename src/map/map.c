/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/15 13:58:46 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_error_code	map_create(t_map **ret)
{
	t_error_code	err;
	t_map			*tmp;

	if (!ret)
		return (ERROR);
	tmp = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!tmp)
		return (ALLOCATION_ERROR);
	err = player_create(&(tmp->p));
	if (SUCCESS == err)
		err = sprite_mngr_create(&(tmp->sm));
	if (SUCCESS == err)
		err = plane_mngr_create(&(tmp->pm));
	if (SUCCESS != err)
	{
		map_destroy(&tmp);
		return (ALLOCATION_ERROR);
	}
	*ret = tmp;
	return (SUCCESS);
}

void	map_destroy(t_map **obj)
{
	t_map	*tmp;

	if (!obj || !*obj)
		return ;
	tmp = *obj;
	if (tmp->file)
		tab_deep_destroy(&(tmp->file));
	if (tmp->map)
		tab_deep_destroy(&(tmp->map));
	if (tmp->p)
		player_destroy(&(tmp->p));
	if (tmp->sm)
		sprite_mngr_destroy(&(tmp->sm));
	if (tmp->pm)
		plane_mngr_destroy(&(tmp->pm));
	ft_bzero(tmp, sizeof(t_map));
	free(tmp);
	*obj = NULL;
}
