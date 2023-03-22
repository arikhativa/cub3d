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

t_error_code	game_load(t_game *g, char *path_to_map)
{
	t_error_code	err;

	err = map_read_raw(g->map, path_to_map);
	if (SUCCESS == err)
		err = map_validate(g->map->file);
	if (SUCCESS == err)
		err = map_load(g->map);
	if (SUCCESS == err)
		err = map_post_load_validation(g->map);
	return (err);
}
