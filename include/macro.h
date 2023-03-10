/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:35:42 by yoav              #+#    #+#             */
/*   Updated: 2023/02/15 10:33:20 by yrabby           ###   ########.fr       */
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

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

#endif
