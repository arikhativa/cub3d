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

#include "sprite_mngr.h"

static t_error_code	sprite_mngr_init(t_sprite_mngr *sm, void *mlx)
{
	t_error_code	err;
	int				i;

	if (!sm)
		return (ERROR);
	i = 0;
	while (i < SPRITES_IN_MAP)
	{
		err = sprite_create(&sm->sprites[i], mlx);
		if (err)
			return (err);
		i++;
	}
	return (SUCCESS);
}

t_error_code	sprite_mngr_create(t_sprite_mngr **ret, void *mlx)
{
	t_error_code	err;
	t_sprite_mngr	*tmp;

	if (!ret)
		return (ERROR);
	tmp = (t_sprite_mngr *)ft_calloc(1, sizeof(t_sprite_mngr));
	if (!tmp)
		return (ALLOCATION_ERROR);
	err = sprite_mngr_init(tmp, mlx);
	if (SUCCESS != err)
	{
		sprite_mngr_destroy(&tmp);
		return (err);
	}
	*ret = tmp;
	return (SUCCESS);
}

static void	sprite_mngr_clear(t_sprite_mngr *sm)
{
	int	i;

	if (!sm)
		return ;
	i = 0;
	while (i < SPRITES_IN_MAP)
	{
		sprite_destroy(&sm->sprites[i]);
		i++;
	}
}

void	sprite_mngr_destroy(t_sprite_mngr **obj)
{
	t_sprite_mngr	*tmp;

	if (!obj || !*obj)
		return ;
	tmp = *obj;
	sprite_mngr_clear(tmp);
	ft_bzero(tmp, sizeof(t_sprite_mngr));
	free(tmp);
	*obj = NULL;
}
