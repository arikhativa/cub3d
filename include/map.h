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
# include "plane_mngr.h"
# include "point.h"
# include "cub.h"
# include "file_mngr.h"
# include "tab.h"

typedef struct s_map
{
	t_plane_mngr	*pm;
	t_sprite_mngr	*sm;
	t_player		*p;
	t_point			size;
	char			**map;
	char			**file;
}	t_map;

t_error_code	map_create(t_map **ret, void *mlx);
t_error_code	map_read_raw(t_map *m, char *path);
t_error_code	map_validate(char **file);
t_error_code	map_alloc_map(t_map *m);
void			map_destroy(t_map **obj);
t_error_code	map_load(t_map *m);
t_error_code	map_load_map(t_map *m);
t_error_code	map_load_sprite(t_map *m, char *line, char *prefix);
t_error_code	map_load_plane(t_map *m, char *line, char *prefix);
void			map_print(t_map *m);
int				map_get_map_index(char **file);
void			map_get_size(t_map *m);
t_error_code	map_load_player(t_map *m);

#endif
