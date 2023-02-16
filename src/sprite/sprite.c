/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/16 11:14:53 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

t_error_code	sprite_create(t_sprite **ret, void *mlx)
{
	t_sprite		*tmp;

	if (!ret)
		return (ERROR);
	tmp = (t_sprite *)ft_calloc(1, sizeof(t_sprite));
	if (!tmp)
		return (ALLOCATION_ERROR);
	tmp->mlx = mlx;
	*ret = tmp;
	return (SUCCESS);
}

void	sprite_destroy(t_sprite **obj)
{
	t_sprite	*tmp;

	if (!obj && !*obj)
		return ;
	tmp = *obj;
	if (sprite_is_loaded(tmp))
		sprite_unload(tmp);
	ft_bzero(tmp, sizeof(t_sprite));
	free(tmp);
	*obj = NULL;
}
