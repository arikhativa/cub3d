/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:59 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/15 13:59:05 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>

# include "libft.h"
# include "player.h"
# include "error_code.h"
# include "sprite_mngr.h"
# include "point.h"

// textures
// color planes
typedef struct s_map
{
	t_sprite_mngr	*sm;
	t_player		*p;
	t_point			size;
	char			**map;
}	t_map;

t_error_code	map_create(t_map **ret, void *mlx);
void			map_destroy(t_map **obj);

#endif
