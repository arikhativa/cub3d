/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/15 13:36:52 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_error_code	player_create(t_player **ret)
{
	if (ret)
	{
		*ret = (t_player *)ft_calloc(1, sizeof(t_player));
		if (!*ret)
			return (ERROR);
		return (SUCCESS);
	}
	return (ERROR);
}

void	player_destroy(t_player **obj)
{
	t_player	*tmp;

	if (obj && *obj)
	{
		tmp = *obj;
		ft_bzero(tmp, sizeof(t_player));
		free(tmp);
		*obj = NULL;
	}
}

void	player_init(t_player *obj, t_point pos, t_direction dir)
{
	if (obj)
	{
		obj->pos = pos;
		obj->dir = dir;
	}
}
