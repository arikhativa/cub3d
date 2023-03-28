/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/03/27 16:11:30 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <stdlib.h>

# include "libft.h"
# include "error_code.h"
# include "direction.h"
# include "fpoint.h"

typedef struct s_player
{
	t_fpoint		pos;
	t_fpoint		cam;
	t_direction		dir;
}				t_player;

t_error_code	player_create(t_player **ret);
void			player_init(t_player *obj, t_point pos, t_direction dir);
void			player_destroy(t_player **obj);
t_bool			player_is_loaded(t_player *p);
void			player_print(t_player *p);

#endif
