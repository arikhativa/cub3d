/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:45:15 by yoav              #+#    #+#             */
/*   Updated: 2023/02/07 10:46:51 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_CODE_H
# define ERROR_CODE_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# include "macro.h"
# include "libft.h"

typedef enum s_error_code
{
	ERROR = -1,
	SUCCESS = 0,
	BUILTIN_RET_VAL_ERROR = 1,
	NO_BUILTIN_ERROR,
	ALLOCATION_ERROR,
	SYNTAX_ERROR,
	NEW_PROC_ERROR,
	END,
	CONTINUE,
	PIPE_LIMIT_ERROR,
	EOF_SUCCESS,
	HEREDOC_ERR_ON_INTERACTIVE_MODE,
	HEREDOC_SIGNAL_EXIT,
	NO_INPUT,
	SIGNAL_ERROR,
	OPEN_ERROR,
	END_OF_TRANSMISSION,
	CLOSE_ERROR,
	EXPORT_INVALID_INPUT,
	EXPORT_IGNORE_INPUT,
}	t_error_code;

t_error_code	error_code_print_internal_err(t_error_code err);
void			error_code_print(int size, ...);

#endif
