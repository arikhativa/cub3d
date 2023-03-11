/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/14 10:47:54 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <stdlib.h>

# include "libft.h"
# include "error_code.h"
# include "map.h"
# include "mlx.h"
# include "screen.h"
# include "mlx_keys.h"

typedef struct s_game
{
	void		*mlx;
	t_map		*map;
	t_screen	*screen;
}				t_game;

t_error_code	game_create(t_game **ret);
void			game_destroy(t_game **obj);
t_error_code	game_load(t_game *g, char *path_to_map);
t_error_code	game_start(t_game *g);
;void			game_draw(t_game *g);

#endif
