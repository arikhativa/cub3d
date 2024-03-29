/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:45:15 by yoav              #+#    #+#             */
/*   Updated: 2023/04/19 12:00:46 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_CODE_H
# define ERROR_CODE_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

# include "macro.h"
# include "libft.h"

# define OPEN_ERROR_MSG			"Error\nopen() failed"
# define EXT_NO_ARG_MSG			"'.cub' map not specified"
# define EXT_TOO_MANY_ARG_MSG	"Too many arguments"
# define EXT_INVALID_FILE_MSG	"Invalid file suffix.\
	 format should be -> <file>.cub"
# define EXT_INVALID_LINE_MSG			"EXT_INVALID_LINE"
# define EXT_BAD_COLOR_MSG				"EXT_BAD_COLOR"
# define EXT_MISSING_PLANE_COLOR_MSG	"EXT_MISSING_PLANE_COLOR"
# define EXT_BAD_CHAR_IN_PLANE_MSG		"EXT_BAD_CHAR_IN_PLANE"
# define EXT_BAD_SPRITE_FILE_MSG		"EXT_BAD_SPRITE_FILE"
# define EXT_BAD_PREFIX_MSG				"EXT_BAD_PREFIX"
# define EXT_MAP_NOT_AT_BOTTOM_MSG		"EXT_MAP_NOT_AT_BOTTOM"
# define EXT_MLX_ERROR_MSG				"EXT_MLX_ERROR"
# define EXT_MISSING_PLAYER_MSG			"EXT_MISSING_PLAYER"
# define EXT_MAP_OPEN_MSG				"EXT_MAP_OPEN"
# define EXT_DUPLICATE_SETTING_MSG		"EXT_DUPLICATE_SETTING"
# define EXT_MAP_TOO_BIG_MSG			"EXT_MAP_TOO_BIG"
# define EXT_EMPTY_FILE_MSG				"EXT_EMPTY_FILE"
# define EXT_NO_FILE_MSG				"EXT_NO_FILE"

typedef enum s_error_code
{
	ERROR = -1,
	SUCCESS = 0,
	STOP,
	ALLOCATION_ERROR,
	MLX_NEW_ING,
	MLX_NEW_WIN,
	SPRITE_LOAD_GET_DATA_ADDR,
	SPRITE_LOAD_FILE_TO_IMG,
	OPEN_ERROR,
	NULL_POINTER,
	EXT_MLX_ERROR,
	EXT_INVALID_LINE,
	EXT_BAD_COLOR,
	EXT_MISSING_PLANE_COLOR,
	EXT_BAD_CHAR_IN_PLANE,
	EXT_BAD_SPRITE_FILE,
	EXT_BAD_PREFIX,
	EXT_TOO_MANY_ARG,
	EXT_NO_ARG,
	EXT_MAP_NOT_AT_BOTTOM,
	EXT_INVALID_FILE,
	EXT_MISSING_PLAYER,
	EXT_MAP_OPEN,
	EXT_DUPLICATE_SETTING,
	EXT_MAP_TOO_BIG,
	EXT_EMPTY_FILE,
	EXT_NO_FILE,
}	t_error_code;

t_error_code	error_code_print_on_exit(t_error_code err);
void			error_code_print(int size, ...);
t_error_code	error_code_print_ext3(t_error_code err);
t_error_code	error_code_print_msg(char *msg, t_error_code err);

#endif
