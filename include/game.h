/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/04/11 23:19:35 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <stdlib.h>

# include "libft.h"
# include "error_code.h"
# include "map.h"
# include "mlx.h"
# include "vertical_stripe.h"
# include "screen.h"
# include "player.h"
# include "mlx_keys.h"
# include "ray_caster.h"

typedef struct s_game
{
	void				*mlx;
	t_map				*map;
	t_screen			*screen;
	t_ray_caster		*rc;
	t_vertical_stripe	*vs;
}				t_game;

t_error_code	game_create(t_game **ret);
void			game_destroy(t_game **obj);
t_error_code	game_init(t_game *g);
t_error_code	game_load(t_game *g, char *path_to_map);
t_error_code	game_start(t_game *g);
void			game_draw(t_game *g);
void			game_handler_vision(t_game *g, int key);
void			game_handler_movement(t_game *g, int key);
void			game_handler_exit(t_game *g);

#endif
