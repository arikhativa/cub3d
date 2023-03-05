/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:32:07 by yrabby            #+#    #+#             */
/*   Updated: 2023/02/15 13:38:26 by yrabby           ###   ########.fr       */
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
	DIR_INVALID = 4
}	t_direction;

t_direction		direction_char_to_dir(char c);
char			direction_dir_to_char(t_direction dir);

#endif
