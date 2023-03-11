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

t_error_code	game_start(t_game *g)
{
	int	floor_color;
	int	celling_color;

	floor_color = map_get_floor_color(g->map);
	celling_color = map_get_celling_color(g->map);
	screen_draw_background(g->screen, celling_color, floor_color);
	mlx_loop(g->mlx);
	if (!g)
		return (0);
	return (0);
}
