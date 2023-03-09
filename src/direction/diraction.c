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

#include "direction.h"

t_direction	direction_char_to_dir(char c)
{
	if (c == NORTH_CHAR)
		return (NORTH);
	else if (c == SOUTH_CHAR)
		return (SOUTH);
	else if (c == EAST_CHAR)
		return (EAST);
	else if (c == WEST_CHAR)
		return (WEST);
	else
		return (DIR_INVALID);
}

char	direction_dir_to_char(t_direction dir)
{
	if (dir == NORTH)
		return (NORTH_CHAR);
	else if (dir == SOUTH)
		return (SOUTH_CHAR);
	else if (dir == EAST)
		return (EAST_CHAR);
	else if (dir == WEST)
		return (WEST_CHAR);
	else
		return ('?');
}
