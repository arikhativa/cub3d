/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/15 13:46:21 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define ROTATION_SPEED	10
# define MOVEMENT_SPEED	1

# include <stdlib.h>

# include "libft.h"
# include "error_code.h"
# include "direction.h"
# include "fpoint.h"
# include "radian.h"

typedef struct s_player
{
	t_fpoint	pos;
	t_direction	start_dir;
	double		dir;
}				t_player;

t_error_code	player_create(t_player **ret);
void			player_init(t_player *obj, t_fpoint pos, t_direction dir);
void			player_destroy(t_player **obj);
t_bool			player_is_loaded(t_player *p);
void			player_print(t_player *p);
void			player_rotate_right(t_player *p);
void			player_rotate_left(t_player *p);
void			player_move_forward(t_player *p, char **map);
void			player_move_backward(t_player *p, char **map);
void			player_move_left(t_player *p, char **map);
void			player_move_right(t_player *p, char **map);
void			player_move(t_player *p, char **map, double sloop);

#endif
