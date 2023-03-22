/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/03/22 12:19:33 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_error_code	game_create(t_game **ret)
{
	t_error_code	err;
	t_game			*tmp;

	if (!ret)
		return (ERROR);
	tmp = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!tmp)
		return (ALLOCATION_ERROR);
	err = map_create(&tmp->map);
	if (err == SUCCESS)
		err = screen_create(&tmp->screen);
	if (err == SUCCESS)
		err = vertical_stripe_create(&tmp->vs);
	if (err == SUCCESS)
		err = ray_caster_create(&tmp->rc);
	if (err != SUCCESS)
	{
		game_destroy(&tmp);
		return (err);
	}
	*ret = tmp;
	return (SUCCESS);
}

void	game_destroy(t_game **obj)
{
	t_game	*tmp;

	if (!obj || !*obj)
		return ;
	tmp = *obj;
	if (tmp->map)
		map_destroy(&(tmp->map));
	if (tmp->screen)
		screen_destroy(&(tmp->screen));
	if (tmp->vs)
		vertical_stripe_destroy(&(tmp->vs));
	if (tmp->rc)
		ray_caster_destroy(&(tmp->rc));
	if (tmp->mlx)
	{
		//mlx_destroy_display(tmp->mlx);
		free(tmp->mlx);
	}
	ft_bzero(tmp, sizeof(t_game));
	free(tmp);
	*obj = NULL;
}
