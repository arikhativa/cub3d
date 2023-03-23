/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:46:30 by yrabby            #+#    #+#             */
/*   Updated: 2023/03/23 06:59:10 by yrabby           ###   ########.fr       */
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
		(*ret)->dir = DIR_INVALID;
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

t_bool	player_is_loaded(t_player *p)
{
	if (!p || DIR_INVALID == p->dir)
		return (FALSE);
	return (TRUE);
}

void	player_init(t_player *obj, t_point pos, t_direction dir)
{
	if (obj)
	{
		obj->pos = point_to_fpoint(pos);
		// obj->pos.x += 0.5;
		// obj->pos.y += 0.5;
		obj->dir = dir;
	}
}

void	player_print(t_player *p)
{
	if (p)
	{
		printf("player: {dir: %c, pos: ", direction_dir_to_char(p->dir));
		fpoint_print(p->pos);
		printf("}\n");
	}
}
