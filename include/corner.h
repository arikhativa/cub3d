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

#ifndef CORNER_H
# define CORNER_H

# include <stdlib.h>

# include "fpoint.h"
# include "point.h"
# include "macro.h"

typedef enum e_corner_type
{
	PART_OF_TOP_WALL,
	PART_OF_BOTTOM_WALL,
	PART_OF_LEFT_WALL,
	PART_OF_RIGHT_WALL,
	NOT_A_CORNER,
}	t_corner_type;

typedef struct s_corner
{
	t_bool	top_r;
	t_bool	top_l;
	t_bool	bot_r;
	t_bool	bot_l;
}	t_corner;

t_corner_type	get_corner_type(char **map, t_fpoint corner);

#endif
