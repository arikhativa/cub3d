/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycarro <ycarro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:35:42 by yoav              #+#    #+#             */
/*   Updated: 2023/04/12 11:08:32 by ycarro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

# define CUB3D_STR			"cub3d"
# define NEW_LINE_STR		"\n"
# define NEW_LINE_CHAR		'\n'
# define EMPTY_STR			""
# define PLAYER_DIR_STR		"NSEW"
# define WALL_CHAR			'1'
# define SPACE_CHAR			' '
# define EMPTY_SPACE_CHAR	'0'
# define SCREEN_SIZE_X		1024
# define SCREEN_SIZE_Y		768
# define BITS_IN_CHAR		8
# define FOV_IN_DEGREE		66
# define ON_DESTROY			17

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

#endif
