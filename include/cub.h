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

#ifndef CUB_H
# define CUB_H

# include <stdlib.h>

# include "libft.h"
# include "plane_mngr.h"
# include "error_code.h"
# include "direction.h"
# include "file_mngr.h"
# include "atoi_overflow.h"
# include "rgb.h"
# include "macro.h"

# define NORTH_STR			"NO "
# define SOUTH_STR			"SO "
# define WEST_STR			"WE "
# define EAST_STR			"EA "
# define CEILING_STR		"C "
# define FLOOR_STR			"F "
# define VALID_MAP_CHARS	" 01NSWE"

typedef enum e_line_type
{
	LINE_TYPE_NORTH,
	LINE_TYPE_SOUTH,
	LINE_TYPE_WEST,
	LINE_TYPE_EAST,
	LINE_TYPE_FLOOR,
	LINE_TYPE_CEILING,
	LINE_TYPE_EMPTY,
	LINE_TYPE_MAP,
	LINE_TYPE_INVALID,
}				t_line_type;

t_error_code	cub_validate_by_line(char **file);
t_error_code	cub_validate_map_at_bottom(char **file);
t_error_code	cub_validate_line(char *line);
t_line_type		cub_get_line_type(char *line);
t_direction		cub_get_direction(char *prefix);
t_plane_type	cub_get_plane_type(char *prefix);
t_rgb			cub_get_rgb(char *line);

#endif
