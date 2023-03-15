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
	if (tmp->mlx)
	{
		mlx_destroy_display(tmp->mlx);
		free(tmp->mlx);
	}
	ft_bzero(tmp, sizeof(t_game));
	free(tmp);
	*obj = NULL;
}