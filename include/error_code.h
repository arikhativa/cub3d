/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:45:15 by yoav              #+#    #+#             */
/*   Updated: 2023/02/16 10:59:57 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_CODE_H
# define ERROR_CODE_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# include "macro.h"
# include "libft.h"

# define EXT_NO_ARG_MSG			"'.cub' map not specified"
# define EXT_TOO_MANY_ARG_MSG	"Too many arguments"
# define EXT_INVALID_FILE_MSG	"Invalid file suffix.\
	 format should be -> <file>.cub"

typedef enum s_error_code
{
	ERROR = -1,
	SUCCESS = 0,
	ALLOCATION_ERROR,
	SPRITE_LOAD_GET_DATA_ADDR,
	SPRITE_LOAD_FILE_TO_IMG,
	EXT_TOO_MANY_ARG,
	EXT_NO_ARG,
	EXT_INVALID_FILE,
}	t_error_code;

t_error_code	error_code_print_on_exit(t_error_code err);
void			error_code_print(int size, ...);

#endif
