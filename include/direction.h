/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:32:07 by yrabby            #+#    #+#             */
/*   Updated: 2023/03/23 11:25:25 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIRECTION_H
# define DIRECTION_H

# define NORTH_CHAR	'N'
# define SOUTH_CHAR	'S'
# define WEST_CHAR	'W'
# define EAST_CHAR	'E'

typedef enum e_direction
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3,
	PERFECT_NE,
	PERFECT_NW,
	PERFECT_SE,
	PERFECT_SW,
	NE,
	NW,
	SE,
	SW,
	DIR_INVALID,
}	t_direction;

t_direction		direction_char_to_dir(char c);
char			direction_dir_to_char(t_direction dir);

#endif
