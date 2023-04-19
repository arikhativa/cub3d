/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/04/19 14:24:03 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_error_code	game_init(t_game *g)
{
	t_error_code	err;

	g->mlx = mlx_init();
	if (!g->mlx)
		return (EXT_MLX_ERROR);
	map_init(g->map, g->mlx);
	err = screen_init(g->screen, g->mlx);
	if (err == SUCCESS)
		vertical_stripe_init(g->vs, g->screen);
	return (err);
}

t_error_code	game_load(t_game *g)
{
	t_error_code	err;

	err = map_validate(g->map->file);
	if (SUCCESS == err)
		err = map_load(g->map);
	if (SUCCESS == err)
		err = map_post_load_validation(g->map);
	if (err == SUCCESS)
		ray_caster_init(g->rc, g->screen->size.x, g->map, g->vs);
	return (err);
}
